#include <iostream>
using namespace std;

int gcd (int a, int b) {
    if (a == 0)
        return b;
    return gcd ( b % a, a );
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
	    int n;
	    cin >> n;
	    
	    unsigned int result = 1;
	    for (int i = 2; i < n; i++) {
	        if ( gcd(i, n) == 1 ) {
	            result++;
	        }
	    }
	    cout <<  result << endl;
	}
}