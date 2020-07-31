#include <bits/stdc++.h>

#define ine long long
#define endl "\n"

using namespace std;

int a[200010];

int32_t main()
{
    freopen("input.txt", "r", stdin);
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		for(int i=0;i<n;i++)
			cin >> a[i];

	//	a[n] = -1;

		map <int,int> m1,m2;
		int cnt = 1;
		bool flag = true;

		for(int i=0;i<n;i++)
		{
			if(a[i] == a[i+1])
				cnt++;
			else
			{
				m1[a[i]]++;
				m2[cnt]++;
				cnt = 1;
			}
		}
		for (map<int, int>::iterator i = m1.begin(); i != m1.end(); i++) {
            cout << i->first << " " << i->second << endl;
		}
		cout << endl;
		for (map<int, int>::iterator i = m2.begin(); i != m2.end(); i++) {
            cout << i->first << " " << i->second << endl;
		}
		cout << endl;

		for(std::map<int, int>::iterator i = m1.begin(); i != m1.end(); i++)
		{
			if(i->second != 1)
			{
				flag = false;
				break;
			}
		}

		for(std::map<int, int>::iterator i = m2.begin(); i != m2.end(); i++)
		{
			if(i->second != 1)
			{
				flag = false;
				break;
			}
		}

		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
