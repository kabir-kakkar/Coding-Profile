// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


bool is_k_palin(string s,int k);

int main() {
    freopen("input.txt", "r", stdin);
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		string s ;
		cin>>s;
		int k;
		cin>>k;

		cout<<is_k_palin(s,k)<<endl;
	}
	return 0;
}// } Driver Code Ends


bool is_k_palin(string s,int k) {
    string r = s;
    reverse(r.begin(), r.end());

    int m = s.length();
    int n = m;

    // LOOKUP TABLE
    int T[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            if (i==0 || j==0) {
                T[i][j] = i+j;
            } else if (s[i-1] == r[j-1]) {
                T[i][j] = T[i-1][j-1];
            } else {
                T[i][j] = 1 + min(T[i-1][j], T[i][j-1]);
            }
        }
    }
    bool flag;
    if (T[m][n] <= 2*k)
        flag = true;
    else
        flag = false;
    return flag;
}
//
//int isKPalin (string X, int m, string Y, int n) {
//
//    // if Either of the string's length is zero then return the string's length
//    if (m == 0 || n == 0)
//        return (m+n);
//
//    // If the last character of both the strings are equal, then ignore the last character
//    if (X[m-1] == Y[n-1]) {
//        return isKPalin(X, m-1, Y, n-1);
//    }
//
//    // If the last character is not same then first decrease the last character from X then Y and recur.
//
//    int x = isKPalin(X, m-1, Y, n);
//
//    int y = isKPalin(X, m, Y, n-1);
//
//    // finally return the minimum of x and y added by 1
//    return (1 + min(x, y));
//}
//
//bool is_k_palin(string s,int k) {
//    string rev = s;
//    reverse(rev.begin(), rev.end());
//    int len = s.length();
//    if (isKPalin(s, len, rev, len) <= 2*k) {
//        return true;
//    } else {
//        return false;
//    }
//}
