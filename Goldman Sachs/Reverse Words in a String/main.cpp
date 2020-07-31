#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.length();
        int j = 0;

        reverse (s.begin(), s.end());

        for (int i = 0; i < n; i++) {
            if (s[i] == '.') {
                reverse (s.begin() + j, s.begin() + i);
                j = i+1;
            }
        }
        reverse (s.begin() + j, s.end());
        cout << s << endl;
    }

    return 0;
}
