#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;

        	int n = str.size();

        	bool table[n][n];
            memset(table, 0, sizeof(table));

        	int maxLength = 1;

        	for (int i = 0; i < n; ++i)
        		table[i][i] = true;

        	int start = 0;
        	bool flag = true;
        	for (int i = 0; i < n - 1; ++i) {
        		if (str[i] == str[i + 1]) {
        			table[i][i + 1] = true;

        			if (flag) {
                        start = i;
                        maxLength = 2;
                        flag = false;
        			}

        		}
        	}

        	for (int k = 3; k <= n; ++k) {
        		for (int i = 0; i < n - k + 1; ++i) {
        			int j = i + k - 1;
        			if (table[i + 1][j - 1] &&  str[i] == str[j]) {
        				table[i][j] = true;
        				if (k > maxLength) {
        					start = i;
        					maxLength = k;
        				}
        			}
        		}
        	}

        	for (int i = start; i < start + maxLength; ++i)
        		cout << str[i];
        	cout << endl;
    }
}
