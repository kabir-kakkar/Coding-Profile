#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;

        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        sort(a, a+n);
        sort(b, b+m);

        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) {
                if ((a[i] + b[j]) == x) {
                    if (flag == false) {
                        cout << a[i] << " " << b[j];
                        flag = true;
                    } else {
                        cout << ", " << a[i] << " " << b[j];
                    }
                }
            }
        }
        if (!flag) {
            cout << "-1";
        }
        cout << "\n";
    }


    return 0;
}
