#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

void findRepeat(int a[], int n);
void scanArray(int a[], int n);

int main()
{

   int a[100], n = 11;

    cout << "Enter the size of the array: ";
    cin >> n;

    scanArray (a, n);
    cout << endl;
    cout << "Repeated terms are: ";
    findRepeat(a, n);
}

void scanArray (int a[], int n)
{
    for (int i = 0; i < n; i ++)
    {
        cout << "\n Enter " << i+1 << " element of array: " ;
        cin >> a[i];
    }
}

void findRepeat (int a[], int n)
{
    int repeat[10], k = 0, index1[10], index2[10];
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
               repeat[k] = a[i];
               index1[k] = i;
               index2[k] = j;
               k++;
            }
        }
    }

    int smallest = 0;

    for (int i = 0; i < k-1; i++)
    {
        for (int j = i+1; j < k; j++)
        {
            if (index2[i] < index2[i+1])
            {
                smallest = i;
            }
        }
    }

    cout << repeat[smallest] << " " << index2[smallest];

}
