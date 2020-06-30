#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int t;
	cin >> t;

	while (t--) {
	    int n, s;
	    cin >> n >> s;

	    int a[n];
	    for (int i = 0; i < n; i++)
	    {
	        cin >> a[i];
	    }
	    int sum = 0;
	    bool flag = false;
	    int s_index = 0;
	    for (int i = 0; i < n; i++) {
	        sum += a[i];
	        while (sum > s) {
	            sum = sum - a[s_index++];
	        }
	        if (sum == s) {
	            cout << s_index+1 << " " << i+1 << endl;
	            flag = true;
	            break;
	        }
	    }
	    if (flag == false) {
	        cout << "-1\n";
	    }
	}

    return 0;
}
