#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int dp[n+1];
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;

        for (int i = 2; i <= n; i++)
        {
            int oneDigit = std::stoi (s.substr (i-1, i));
            int twoDigit = std::stoi (s.substr (i-2, i));

            if (oneDigit >= 1) {
                dp[i] += dp[i-1];
            }
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2];
            }
        }
        cout << dp[n] << "\n";
    }

    return 0;
}
