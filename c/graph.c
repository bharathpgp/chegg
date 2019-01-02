#include <stdio.h>

void readAndPrintVertices(int N)
{
    char name[20];
    int i;
    for (i = 0; i < N; i++)
    {
        fscanf(stdin, "%s", name);
        printf("%d-%s\n", i, name);
    }
}

int main(int argc, int *argv[])
{
    int N;
    fscanf(stdin, "%d", &N);
    printf("N = %d\n", N);
    readAndPrintVertices(N);
    return 0;
}