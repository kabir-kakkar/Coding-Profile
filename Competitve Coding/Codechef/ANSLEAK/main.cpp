#include<bits/stdc++.h>
using namespace std;
int n, m, k;
void input() {
    cin >> n >> m >> k;
}
void solve() {
    int f[n + 1][10];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            f[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            f[i][x]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        int ma = 0;
        int num = 0;
        for (int j = 0; j < 10; ++j) {
            if (f[i][j] > ma) {
                num = j;
                ma = f[i][j];
            }
        }
        cout << num << " ";
    }
    cout << '\n';
}
int32_t main() {
    freopen("input.txt", "r", stdin);
    int t; cin >> t; while (t--) {
        input();
        solve();
    }
    return 0;
}
