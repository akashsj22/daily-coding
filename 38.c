#include <stdio.h>

void insertionSort(int* a, int n)
{
    int passes = n - 1;
    int key, j;

    for(int i = 1; i <= passes; i++)
    {
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void printArray(int* A, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;

    printf("Before sorting:\n");
    printArray(A, n);

    insertionSort(A, n);

    printf("After sorting:\n");
    printArray(A, n);

    return 0;
}
