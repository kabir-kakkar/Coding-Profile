#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int max_ = a[0],
            cur_max = a[0];

        for (int i = 1; i < n; i++) {

                cur_max = max (a[i], cur_max + a[i]);

                max_ = max ( cur_max, max_ );
        }

        cout << max_ << endl;

    }
}
