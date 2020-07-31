#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;

        cin >> n >> k;

        int a[n], d[n], i=0, j=0, temp;
        for (i = 0; i < n; i++)
            cin >> a[i];

        sort (a, a+n);

        for (j = 0; j < n; j++)
        {
            d[j] = *max_element(a, a+n) - *min_element(a, a+n);
            for (i = 0; i < n; i++)
            {
                if (a[i] % k == 0)
                {
                    a[i] = a[i]/k;
                }
                else
                {
                    a[i] = a[i] * k;
                    temp = *max_element(a, a+n) - *min_element(a, a+n);
                    if (temp < d[j])
                    {
                        d[j] = temp;
                    }
                    break;
                }
            }
        }

        cout << *min_element(d, d+n) << "\n";
    }

    return 0;
}

