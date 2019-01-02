import sys, os, re

from os import walk, path
from fnmatch import fnmatch
from re import match
from mutagen.easyid3 import EasyID3

# get directory path from command line
directory = os.path.split(sys.argv[-1])[0]
# get file glob from command line
fileGLob = '*' + os.path.splitext(sys.argv[-1])[1]

regexArtist, regexSong, regexAlbum = None, None, None

# assign corresponding regular expression
for i in range(1, len(sys.argv)):

    if "--artist=" in sys.argv[i]:
        regexArtist = re.sub("--artist=", '', sys.argv[i])

    if "--song=" in sys.argv[i]:
        regexSong = re.sub("--song=", '', sys.argv[i])

    if "--album=" in sys.argv[i]:
        regexAlbum = re.sub("--album=", '', sys.argv[i])

print("{:<40s} by {:<25s} from {:<25s}".format("Title", "Artist", "Album"))
print("-"*80)

for(parent, dirs, files) in walk(directory):

    songPaths = (path.join(parent, fn)
                 for fn in files if fnmatch(fn, fileGLob))

    medias = []
    for fileName in songPaths:
        try:
            media = {k.upper(): v[0] for k, v in EasyID3(fileName).items()}
            if regexArtist is not None and match(regexArtist, media['ARTIST']):
                medias.append(media)
            if regexSong is not None and match(regexSong, media['TITLE']):
                medias.append(media)
            if regexAlbum is not None and match(regexAlbum, media['ALBUM']):
                medias.append(media)
        except Exception as e:
            print("Could not read: '{}' because {}".format(fileName, e))

    for media in medias:
        print("{TITLE:<40s} {ARTIST:<25s}    {ALBUM:<25s}".format(**media))
