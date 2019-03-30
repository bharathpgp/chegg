#include <stdio.h>

void SelectionSort(int array[], int n)
{
    int i, j, idx, tmp;

    for (i = 0; i < n - 1; i++)
    {
        // Find minimum element
        idx = i;
        for (j = i + 1; j < n; j++)
            if (array[j] < array[idx])
                idx = j;

        // Swap the minimum element
        tmp = array[idx];
        array[idx] = array[i];
        array[i] = tmp;
    }
}

/* print an array */
void print(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void Rotate(int array[], int n, int rotElmnt)
{
    int i, times;
    for (i = 0; i < n; i++)
        if (rotElmnt == array[i])            
            times = i;

    for (i = 0; i < times; i++)
    {
        int temp = array[0], j;
        for (j = 0; j < n - 1; j++)
            array[j] = array[j + 1];

        array[j] = temp;
    }
}

int main()
{
    int array[] = {4 , 3, 1, 5, 2};
    int n = sizeof(array) / sizeof(array[0]);
    SelectionSort(array, n);
    printf("Sorted array: \n");
    print(array, n);
    Rotate(array, n, 2);
    print(array, n);
    return 0;
}