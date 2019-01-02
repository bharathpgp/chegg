#define _XOPEN_SOURCE 1
#define _XOPEN_SOURCE_EXTENDED 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ftw.h>
#include <unistd.h>
#define SPARE_FDS 5

int recursive = 0, totCnt, fileCnt, dirCnt, slinkCnt;

int getDetails(const char *file, const struct stat *sb, int flag, struct FTW *s) {
    int val = 0;
    const char *name = file + s->base;

    if ((0 == s->level) || (0 == recursive && s->level > 1)) // stop recursive if -R option given
        return val;

    totCnt++; // total count of all the files

    switch (flag) {
        case FTW_F: // regular file
            fileCnt++;
            break;
        case FTW_D: // directory
            dirCnt++;
            break;
        case FTW_SL: // symbolic link
            slinkCnt++;
            break;
        default:
            printf("%s: unknown flag %d: can't happen!\n", name, flag);
            val = 1;
            break;
    }
    return val;
}

void printUsage(const char *name) {
    fprintf(stderr, "usage: %s [-R] directory path ...\n", name);
    exit(1);
}

// main program
int main(int argc, char **argv) {
    int flags = FTW_PHYS;
    int i, option, nfds;

    while ((option = getopt(argc, argv, "R")) != -1) {
        switch (option) {
            case 'R':
                recursive = 1;
                break;
            default:
                printUsage(argv[0]);
                break;
        }
    }

    if (optind == argc)
        printUsage(argv[0]);

    nfds = getdtablesize() - SPARE_FDS;
    for (i = optind; i < argc; i++) {
        if (nftw(argv[i], getDetails, nfds, flags) != 0) {
            printf("%s: %s: stopped early\n", argv[0], argv[i]);
        }
    }
    printf("Regular Files: %d, percentage(%.2f%%)\n", fileCnt, fileCnt * 100.00 / totCnt);
    printf("Directory: %d, percentage(%.2f%%)\n", dirCnt, dirCnt * 100.00 / totCnt);
    printf("Symbolic Link: %d, percentage(%.2f%%)\n", slinkCnt, slinkCnt * 100.00 / totCnt);
    return 0;
}