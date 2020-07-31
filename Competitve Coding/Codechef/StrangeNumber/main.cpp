#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll no_of_factors (ll x) {
    ll c = 0;
    while (x%2 == 0) {
        c++;
        x = x/2;
    }
    for (ll i = 3; i <= sqrt(x); i++) {
        while (x%i == 0) {
            c++;
            x /= i;
        }
    }
    // Adding 1 to count
    if (x > 1)
        c++;

    return c;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;

    while (T--)
    {
        ll X, K;
        cin >> X >> K;

        ll c = no_of_factors(X);

        if (K <= c)
            cout << "1\n";
        else
            cout << "0\n";
    }
}
