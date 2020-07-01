#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;

        int a[n];
        map<int, int> s;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        for (int i = 0; i < m; i++) {
            int temp;
            cin >> temp;
            s[temp++];
        }

        bool flag = false;

        for (int i = 0; i < n; i++) {
            if (s.find(x - a[i]) != s.end()) {
                    if (flag == false) {
                        cout << a[i] << " " << x-a[i];
                        flag = true;
                    } else {
                        cout << ", " << a[i] << " " << x-a[i];
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
