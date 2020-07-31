#include <bits/stdc++.h>
using namespace std;

int strstr (string s, string x);
void computeLPSArray (string x, int m, int* lps);

int main() {
	// your code goes here
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;

	while (t--) {
	    string s, x;
	    cin >> s >> x;

	    cout << strstr(s, x) << endl;
	}
	return 0;
}

int strstr (string s, string x) {

//    SIMPLE APPROACH 1
//    int k;
//    for(int i = 0; i < s.length(); i++) {
//         k = i;
//        for (int j = 0; j < x.length(); j++) {
//            if (x[j] == s[k]) {
//                k++;
//                if (j == x.length()-1) {
//                    return i;
//                }
//            } else {
//                break;
//            }
//        }
//    }
//    return -1;

    //SIMPLE APPROACH 2
//    return s.find(x);

    //KMP APPROACH
    int M = x.length();
    int N = s.length();

    int lps[M];

    computeLPSArray (x, M, lps);

    int i = 0, j = 0;
    while ( i < N ) {
        if (x[j] == s[i]) {
            j++;
            i++;
        }
        if (j == M) {
            return (i-j);
            j = lps[j-1];
        }
        else if (i < N && x[j] != s[i]) {
            if (j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
    return -1;
}

void computeLPSArray (string x, int m, int* lps) {
    int len = 0;

    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (x[i] == x[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
