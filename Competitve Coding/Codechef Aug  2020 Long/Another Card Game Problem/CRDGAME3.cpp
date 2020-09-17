#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
	    int c, r;
	    cin >> c >> r;
	   
	    c = (c-1)/9 + 1;
	    r = (r-1)/9 +1;
	    
	    if (c < r) {
	        cout << "0 " << c << endl;
	    } else {
	        cout << "1 " << r << endl;
	    }
	}
}