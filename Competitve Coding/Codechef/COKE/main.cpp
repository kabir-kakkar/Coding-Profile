#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen ("input.txt", "r", stdin);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M, K, L, R;
        int C[N], P[N];
        int i, t[N] = {};

        cin >> N >> M >> K >> L >> R;

        for (i = 0; i < N; i++)
        {
            cin >> C[i] >> P[i];

            t[i] = C[i];

            if ( t[i] > K+1)
                t[i] = t[i]-1 + 1;
            else if ( t[i] < K-1)
                t[i] = t[i]+1 + 1;
            else if ((K-1 <= t[i]) && (t[i] <= K+1))
                t[i] = K + 1;
        }

        for (i = 0 ; i < N; i++)
        {
         cout << t[i] << "\t";
        }
        cout << "\n";
    }

    return 0;
}
