#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    int A[101];

    A[0] = 0;
    A[1] = 1;

    for (int i = 2; i < 60; i++)
        A[i] = (A[i-1] + A[i-2])%10;

    while (t--)
    {
        ll n;
        cin >> n;

        ll p = 1;
        while (p*2 <= n)
            p = p*2;

        p = (p-1)%60;
        cout << A[p] << endl;
    }

    return 0;
}
