#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    while (T--) {
        ll N;
        cin >> N;
        ll A[100000] = {0};
        ll i, j;
        for (i = 0; i < N; i++){
            cin >> A[i];
        }
        bool flag = true;
        for (i=0; i <N; i++) {
            if (A[i] == 1) {
                for (j=i+1; j < i+6; j++) {
                    if (A[j] == 1) {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag)
                break;
        }


            if (flag)
                cout << "YES\n";
            else
                cout << "NO\n";
    }
}
