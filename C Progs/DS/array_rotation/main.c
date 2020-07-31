#include <stdio.h>
#include <stdlib.h>

void leftRotateByOne(int arr[], int n)
{
    int temp = arr[0], i;
    for (i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[i] = temp;
}

void leftRotate(int arr[], int d, int n)
{
    int i;
    for (i = 0; i < d; i++)
        leftRotateByOne (arr, n);
}

void printArr (int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(a)/sizeof(a[0]);

    printArr(a, n);
    printf("\n");
    int d;
    scanf ("%d", &d);

    leftRotate(a, d, n);
    printArr(a, n);
}
