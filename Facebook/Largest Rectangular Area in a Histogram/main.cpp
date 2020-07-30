#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen ("input.txt", "r", stdin);
    int t;

    while (t--) {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << getMaxArea(a, n) << endl;
    }

    return 0;
}
