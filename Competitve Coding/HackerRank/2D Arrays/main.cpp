#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int arr[6][6], sum=0, max_sum = -9999, i, j;

    for (i=0; i < 6; i++)
    {
        for (j=0; j<6; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (i=1; i < 5; i++)
    {
        for (j=1; j < 5; j++)
        {
            sum = arr[i][j] + arr[i-1][j] + arr[i-1][j-1] + arr[i-1][j+1] + arr[i+1][j] + arr[i+1][j-1] + arr[i+1][j+1];
            if (max_sum < sum)
                max_sum = sum;
        }
    }

    cout << max_sum << "\n";

    return 0;
}
