#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int a[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        
        bool check[n];
        for (int i = 0; i < n; i++) {
            if (a[0][i] == i+1) {
                check[i] = true;
            } else {
                check[i] = false;
            }
        }
        
        int cnt = 0;
        for (int i = n-1; i >= 1; --i) {
            if (check[i] == false) {
                cnt++;
                for (int j = i; j >= 1; --j) {
                    check[j] = check[j] ? false : true; // This will invert values of true and false
                }
            }
        }
        cout << cnt << endl;
    }
    
	return 0;
}
