#include <bits/stdc++.h>
using namespace std;

vector<string> solve(string s);

int main()
{
   //freopen("input.txt", "r", stdin);
   // int t;
   // cin >> t;

   // while (t--) {
        string s;
        cin >> s;

        vector<string> res;
        res = solve(s);
        for (string a: res) {
            cout << a << endl;
        }
    //}
}

vector<string> solve(string s) {

    vector<string> res;
    int n = s.size();

    bool dp[n][n];

    for(int i = 0 ; i < n ; i++) {
        dp [i][i] = 1;
    }

    for(int k = 2 ; k <= n ; k++){
        for(int i = 0 ; i < n-k+1 ; i++) {
            int j = i + k - 1;
            if(k == 2) {
                bool val = (s[i] == s[j]);
                dp[i][j] = val;
            }
            else {
                bool val = (s[i] == s[j]) && (dp[i+1][j-1]);
                dp[i][j] = val;
            }
        }
    }

    for(int i = 0 ; i < n - 2 ; ++i){
        if(dp[0][i]) {
            for(int j = i+1 ; j < n - 1 ; ++j) {
                 if(dp[i+1][j] && dp[j+1][n-1]) {
                    res.push_back(s.substr(0,i + 1));
                    res.push_back(s.substr(i+1,j-i));
                    res.push_back(s.substr(j+1,n-j));
                    return res;
                }
            }
        }
    }
    if(res.empty())
        res.push_back("Impossible");
    return res;
}


