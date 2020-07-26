#include <bits/stdc++.h>
using namespace std;



bool isPerfectSquare(int n)
{
    for (int i = 1; i * i <= n; i++) {

        // If (i * i = n)
        if ((n % i == 0) && (n / i == i)) {
            return true;
        }
    }
    return false;
}

int main() {
	//code
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;

	while (t--) {
	    int n;
	    cin >> n;

	    int ele;
	    for (int i = 0; i < n; i++) {
	       cin >> ele;
	       // Benet's Formula
	       bool c1 = isPerfectSquare(5*ele*ele - 4);
	       bool c2 = isPerfectSquare(5*ele*ele + 4);
	       if ( c1 || c2 ) {
	           cout << ele << " ";
	       }
	    }
	   cout << endl;
	}

	return 0;
}


