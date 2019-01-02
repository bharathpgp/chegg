
/**
 * merge.c
 */

/* Merge a[] of size m and b[] of size n into c[]. */
#include "mergesort.h"

void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int a[], int b[], int c[], int m, int n)
{
    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    while (i < m) /* pick up any remainder */
        c[k++] = a[i++];
    while (j < n)
        c[k++] = b[j++];

    // printf("------\n");
    // print(a, m);
    // print(b, n);
    // print(c, k);
}
