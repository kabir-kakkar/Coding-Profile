#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ll t;
	cin >> t;
	
	while (t--) 
	{
    	ll N, K;
    	cin >> N >> K;
    	
    	int m = -1;
    	int moves = INT_MAX;
    	
    	for (ll i = 0; i < N; i++) {
    	    int temp;
    	    cin >> temp;
    	        
    	    if (K % temp == 0) {
    	        int new_move = K / temp;
    	        if (new_move < moves) {
    	            m = temp;
    	            moves = new_move;
    	        }
    	    }
    	}
    	
    	cout << m << endl;
	}
	
	
	
	return 0;
}
