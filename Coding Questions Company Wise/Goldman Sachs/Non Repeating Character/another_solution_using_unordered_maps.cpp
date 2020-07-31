#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        unordered_map<char, int> m;
        for (int i = 0; i < n; i++) {
            m[s[i]]++;
        }

        bool flag = false;
        //unordered_map<char, int>::iterator itr;

        for (int i = 0; i < n; i++) {
            if ( m[s[i]] == 1) {
                flag = true;
                cout << s[i] << endl;
                break;
            }
        }

        if (!flag)
            cout << "-1\n";
    }
}
