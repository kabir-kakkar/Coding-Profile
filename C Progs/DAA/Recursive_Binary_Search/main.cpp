#include <bits/stdc++.h>
using namespace std;

int arr[100];

int RBS (int first, int last, int key)
{
    if (first == last) {
        if (key == arr[key])
            return first;
        else
            return -1;
    } else {
        int mid = (first + last)/2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            return RBS(first, mid-1, key);
        else if (key > arr[mid])
            return RBS (mid+1, last, key);
        else
            return -1;
    }
}

int main()
{
    int n, key, T;

    freopen ("input.txt", "r", stdin);

    cin >> T;

    while (T--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        cin >> arr[i];

        cin >> key;

        int ans = RBS (0, n, key);

        if (ans != -1)
            cout << ans+1 << "\n";
        else
            cout << "Not found\n";
    }
}
