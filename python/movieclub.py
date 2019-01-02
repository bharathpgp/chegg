# dictionary data structure to hold movie club data
data = {"Mary": [("Spiderman", 'G', 1)],
        "Frank": [("Beauty and the Beast", "G", 1), ("Kung Fu Panda", "G", 5), ("Cinderella", "G", 1)]}

# display all movie clum members
def displayAllMembers():
    if len(data) > 0:
        print("Club Members\n===================")
        for member in data.keys():
            print(member)
    else:
        print("No members")

# display movies for a specific member
def displayMovieInfo():
    name = input("Please enter the member's name: ")
    movies = data.get(name)
    if movies is None:
        print("Sorry, member not found")
    else:
        if len(movies) > 0:
            print("Movies for club member: {0}".format(name))
            print("Movie                    Rating  Watched\n========================================")
            for movie in movies:
                movie_name, rating, watched = movie
                print("{0:25s}{1:8s}{2}".format(movie_name, rating, watched))
        else:
            print("No movies")

# display menu options
def menu():
    print("1. Display all members")
    print("2. Display all movie information for a member")
    print("3. Increment the times a specific movie was watched by a member")
    print("4. Add a movie for a member")
    print("5. Add a new member")
    print("Q. Quit")
    return input("Please enter a selection: ")

# increment movies watched times
def increaseMovieWatchedCount():
    name = input("Please enter the member's name: ")
    members = data.keys()
    if name not in members:
        print("Sorry, member not found")
    else:
        movieName = input("Please enter the name of the movie: ")
        movies = data.get(name)
        found = False
        for i in range(0, len(movies)):
            movie = list(movies[i])
            if movie[0] == movieName:
                found = True
                break

        if found is True:
            movie = list(movies[i])
            movie[2] += 1
            movies[i] = tuple(movie)
            print("Times watched incremented")
        else:
            print("Sorry, movie title not found")

# add new movie to a member
def addMovie():
    name = input("Please enter the member's name: ")
    members = data.keys()
    if name not in members:
        print("Sorry, member not found")
    else:
        movieName = input("Please enter the name of the movie: ")
        movies = data.get(name)
        found = False
        for i in range(0, len(movies)):
            movie = list(movies[i])
            if movie[0] == movieName:
                found = True
                break

        if found is True:
            print("Sorry that movie already exists")
        else:
            times = int(input("Enter times watched: "))
            rating = input("Enter rating: ")
            movies.append((movieName, rating, times))
            data[name] = movies
            print("Movie added")

# add a new member to movie club
def addMember():
    name = input("Member Name: ")
    if data.get(name) is None:
        member = {name: []}
        data.update(member)
        print("Member added")
    else:
        print("Member already exist")

# main program to repeatedly ask user input
def main():
    print("Welcome to the Movie Lover's Club")
    print("=================================")
    while True:
        choice = menu()

        if choice is 'Q':
            break
        else:
            choice = int(choice)

            if choice is 1:
                displayAllMembers()

            elif choice is 2:
                displayMovieInfo()

            elif choice is 3:
                increaseMovieWatchedCount()

            elif choice is 4:
                addMovie()

            elif choice is 5:
                addMember()


if __name__ == "__main__":
    main()







