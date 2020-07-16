#include <bits/stdc++.h>
using namespace std;

int strstr (string s, string x);

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
    return s.find(x);
}
