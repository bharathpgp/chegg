#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int findprime(FILE *fp);
int isprime(int num);

int main(int argc, char **argv) {
  DIR *dir = NULL;
  struct dirent *entry;
  int files = 0;
  int noofthread, count;
  FILE *fp = NULL;

  if (argc < 3) {
    printf("Usage: time ./homework2 numbers 1\n");
    return 0;
  }

  noofthread = atoi(argv[argc-1]);
  dir = opendir(argv[argc-2]);

  if (dir == NULL)
  {
    printf("Opening directory failed");
    return(1);
  }

  while ( entry = readdir(dir) )
  {
    count = 0;
    files++;

    fp = fopen(entry->d_name, "r");

    if ( fp != NULL ) {
      count = findprime(fp);
      printf("Thread has found %d primes in %s\n", count, entry->d_name);
    } else {
      printf("File NULL\n");
    }
    fclose(fp);
  }

  printf("Total Files: %d", files);

  closedir(dir);

  return (0);
}

int findprime(FILE *fp) {

  int count = 0;
  int num = 0;

  if ( fp != NULL ) {
    fscanf (fp, "%d", &num);
    while (!feof(fp))
    {
      fscanf (fp, "%d", &num);
      if (isprime(num)) {
        count++;
      }
    }
  }

  return count;
}

int isprime(int num) {

  int flag = 1;

  for (int i = 2; i <= num / 2; ++i) {

    if (num % i == 0) {
      flag = 0;
      break;
    }
  }

  return flag;
}
