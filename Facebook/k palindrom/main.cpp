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

int isKPalin (string X, int m, string Y, int n) {

    // if Either of the string's length is zero then return the string's length
    if (m == 0 || n == 0)
        return (m+n);

    // If the last character of both the strings are equal, then ignore the last character
    if (X[m-1] == Y[n-1]) {
        return isKPalin(X, m-1, Y, n-1);
    }

    // If the last character is not same then first decrease the last character from X then Y and recur.

    int x = isKPalin(X, m-1, Y, n);

    int y = isKPalin(X, m, Y, n-1);

    // finally return the minimum of x and y added by 1
    return (1 + min(x, y));
}

bool is_k_palin(string s,int k) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    int len = s.length();
    if (isKPalin(s, len, rev, len) <= 2*k) {
        return true;
    } else {
        return false;
    }
}
