#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a[n][n] = {0};

        int num = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = num++;
            }
        }

        // n is odd
        if ( n%2 ) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << a[i][j] << " ";
                }
                cout << "\n";
            }
        } else if ( n%2 == 0) { // n is even

            for (int i = 0; i < n; i++) {

                if ( i%2 == 0 ) { // Even Row
                    for (int j = 0; j < n; j++) {
                        cout << a[i][j] << " ";
                    }
                } else if ( i%2 ) { // Odd Row
                    for (int j = n-1; j >= 0; j--) {
                        cout << a[i][j] << " ";
                    }
                }
                cout << "\n";
            }

        }
    }

    return 0;
}
