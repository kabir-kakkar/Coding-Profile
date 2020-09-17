#include <iostream>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ll t;
	cin >> t;
	
	while (t--) {
    	ll d, p;
    	cin >> d >> p;
    	
    	while (p > 0) {
    	    d = d-p;
    	    p = p/2;
    	}
    	if (d > 0) {
    	    cout << 0 << endl;
    	} else {
    	    cout << 1 << endl;
    	}
	}
	
	
	
	return 0;
}
