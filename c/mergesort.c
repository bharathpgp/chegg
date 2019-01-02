#include "mergesort.h"

void mergesort(int key[], int n)
{
    int j, k, m, *w, *tmpKey, i;

    for (m = 1; m < n; m *= 2);

    w = calloc(m, sizeof(int));
    assert(w != NULL);

    tmpKey = calloc(m, sizeof(int));
    assert(tmpKey != NULL);

    // copy key to tmpkey
    for (i = 0; i < n; i++)
        tmpKey[i] = key[i];

    for (k = 1; k < m; k *= 2)
    {
        for (j = 0; j < m - k; j += 2 * k)
            merge(tmpKey + j, tmpKey + j + k, w + j, k, k);
        for (j = 0; j < m; ++j)
            tmpKey[j] = w[j]; // Write w back into
    }
    free(w);
    // copy tmpkey to key
    for (i = 0; i < n; i++)
        key[i] = tmpKey[i + m - n];
}

int main()
{
    int i, size = 0;
    int arr[] = {10, 1, 34, 56, 78, 11, 20, 45, 100, 0, 18, 31, 39};
    size = sizeof(arr) / sizeof(int);
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    mergesort(arr, size);
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}