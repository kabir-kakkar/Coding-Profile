#include <bits/stdc++.h>
#define boost ios::sync_with_stdio (false); cin.tie(0)
using namespace std;

#define ll long long

ll work(ll nn) {
    long double n = nn;
    return (ll)(((-2.0) + (sqrt(4.0 + 8 * (n * n + n)))) / 4.0);
}

int main() {
    boost;
	int t;
	cin >> t;
	
	while (t--) {
	    ll n;
	    cin >> n;
	    
	    if ( ((n*(n+1))/2) & 1) {
	        cout << 0 << endl;
	        continue;
	    }
	    
	    ll x, cnt = 0;
	    x = work(n);
	    cnt += n-x;
	    
	    if (2 * (x*x + x) == (n*n + n)) {
	        ll a, b;
	        a = x * (x - 1)/2;
	        b = (n-x) * ((n-x) - 1)/2;
	        cnt += a + b;
	    }
	    
	    cout << cnt << endl;
	    
	}
	
	return 0;
}
