#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;

    while (T--)
    {
        ll N;
        cin >> N;

        if (N == 1) {
            cout << 1 << '\n';
			cout << 1 << ' ' << 1 << '\n';
        } else {
            ll c = 0, i = 1;
            vector<ll> cop;
            if (N%2) {
                cout << N/2 << "\n";
            } else {
                cout << N/2-1 << "\n";
            }

            while (c < N/2) {
                if (__gcd(i, i+1) == 1 && i+1 <= N) {
                    cop.push_back(i);
                    cop.push_back(i+1);
                }
                if (__gcd(i+1, i+2) == 1 && i+2 <= N) {
                    cop.push_back(i+2);
                    i = i+3;
                    c++;
                } else {
                    i = i+2;
                    c++;
                }
                if(!cop.empty())
                    cout << cop.size() << " ";

                for (int i = 0; i < cop.size(); i++)
                {
                    cout << cop[i] << " ";
                }
                cop.clear();
                cout << "\n";
            }
        }
    }

    return 0;
}
