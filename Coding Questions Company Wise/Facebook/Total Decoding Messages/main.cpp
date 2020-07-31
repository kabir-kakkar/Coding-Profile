#include <bits/stdc++.h>
using namespace std;

int solve(string, int);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);

	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;

	    string s;
	    cin >> s;

	    int ans = solve(s, n);
	    cout << ans << "\n";
	}
	return 0;
}

int solve (string s, int n) {
    if(s[0]=='0')
        return 0;

    int dp[n+1] = {0};

    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++) {
        if(s[i-1] >= '1')
            dp[i] += dp[i-1];
        if(s[i-2] == '1' ||( s[i-2]=='2' && s[i-1] < '7') )
            dp[i]+=dp[i-2];
    }
    return dp[n];
}


//int main()
//{
//    freopen("input.txt", "r", stdin);
//    int t;
//    cin >> t;
//
//    while (t--)
//    {
//        int n;
//        cin >> n;
//
//        string s;
//        cin >> s;
//
//        int dp[n+1] = {0};
//        dp[0] = 1;
//        dp[1] = s[0] == '0' ? 0 : 1;
//
//        for (int i = 2; i <= n; i++)
//        {
//            stringstream gk1(s.substr (i-1, i));
//            int oneDigit;
//            gk1 >> oneDigit;
//
//            stringstream gk2(s.substr (i-2, i));
//            int twoDigit;
//            gk2 >> twoDigit;
//
//            if (oneDigit >= 1) {
//                dp[i] += dp[i-1];
//            }
//            if (twoDigit >= 10 && twoDigit <= 26) {
//                dp[i] += dp[i-2];
//            }
//        }
//
//        cout << dp[n] << "\n";
//    }
//
//    return 0;
//}
