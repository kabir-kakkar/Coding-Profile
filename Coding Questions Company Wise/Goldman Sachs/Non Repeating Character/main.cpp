#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        // Due to TLE, we use array of size 26 for hashing instead of using maps
        // 26 denotes 26 characters of English Alphabets
        int arr[26]={0};

        // The expression x - 'a' gives you the distance between the character value in x and the first lowercase letter of the alphabet.
        // Will not work for capital letters but since capitals are not here, so we use 'a'.
        for(int i =0;i < n;i++)
	    {
	       arr[s[i]-'a']++;
	    }
	    bool flag = false;
	    for(int i = 0;i<n;i++)
	    {
	        if(arr[s[i]-'a']==1)
	        {
	            cout<<s[i]<<endl;
	            flag = true;
	            break;
	        }
	    }
	    if (!flag)
            cout << "-1\n";
    }
}
