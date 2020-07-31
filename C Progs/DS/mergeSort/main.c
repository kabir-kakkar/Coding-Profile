#include <stdio.h>
#include <stdlib.h>

void merge (int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l+i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m+1+j];

    i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i]; i++;
        }
        else
        {
            arr[k] = R[j]; j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i]; k++; i++;
    }
    while (j < n2)
    {
        arr[k] = R[j]; k++; j++;
    }
}
void mergeSort (int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r-1)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge (arr, l, m, r);
    }
}
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{
    int arr[] = {7, 2, 9, 1, 4, 3, 12, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, n);

    mergeSort(arr, 0, n-1);

    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
