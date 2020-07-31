#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll c = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    while (T--)
    {
        ll N;
        cin >> N;

        vector<ll> P;
        ll i;

        ll temp;
        for (i = 0; i < N; i++) {
            cin >> temp;
            P.push_back(temp);
        }

        sort(P.begin(), P.end(), greater<ll>());
        ll prof=0;

        for(i = 0; i < N; i++) {
            if( P[i]-i > 0) {
                prof += (P[i]-i);
                prof %= c;
            } else {
                break;
            }
        }

        cout << prof << "\n";
    }
    return 0;
}
