#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    int i, j, a[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int k = 0, l = 0;

    while (k < m && l < n)
    {
        // Print first row
        for (i = l; i < n; i++)
        {
            cout << a[k][i] << " ";
        }
        k++;

        //Print first column
        for (i = k; i < m; i++)
        {
            cout << a[i][n-1] << " ";
        }
        n--;

        // Print last row
        if (k < m)
        {
            for (i = n-1; i >= l; i--)
            {
                cout << a[m-1][i] << " ";
            }
            m--;
        }

        // Print last column
        if (l < n)
        {
            for (i = m-1; i >= k; i--)
            {
                cout << a[i][l] << " ";
            }
            l++;
        }
    }

    return 0;
}
