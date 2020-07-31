
#include <iostream>
using namespace std;

void Merge (int a[], int l, int mid, int mid2, int h)
{
    int temp[50];
    int i = l, j = mid2, k = 0;

    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp [k++] = a[i++];

    while (j <= h)
        temp [k++] = a[j++];

    for (i = l, j = 0; i <= h; i++, j++)
        a[i] = temp[j];
}

void MergeSort (int a[], int l, int h)
{
    int mid = 0;
    if (l < h)
    {
        mid = (l+h)/2;
        MergeSort(a, l, mid);
        MergeSort(a, mid+1, h);
        Merge (a, l, mid, mid+1, h);
    }
}

int main()
{
    int arr[] = {10, 9, 13, 7, 16, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    MergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    return 0;
}
