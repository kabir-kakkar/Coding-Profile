#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

	int t;
	cin >> t;

	while(t--)
	{
		int n,m;
		cin >> n >> m;

		map <int,int> freq;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int x;
				cin >> x;

				freq[x]++;
			}
		}

		bool flag = true;

        map<int, int>::iterator itr;
		if(m%2 == 0)
		{
			for( itr = freq.begin(); itr != freq.end(); ++itr)
			{
				if(itr->second%2)
				{
					flag = false;
					break;
				}
			}
		}
		else
		{
			int cnt = 0;

			for(itr = freq.begin(); itr != freq.end(); ++itr)
				cnt += (itr->second%2);

			if(cnt > n)
				flag = false;
		}

		if(!flag)
		{
			cout << -1 << endl;
			continue;
		}

		vector <int> cnt1;
		int a[n][m];
		int id = 0;

		for(itr = freq.begin(); itr != freq.end(); ++itr)
		{
			int x = itr->second;

			if(x%2)
				a[id++][m/2] = itr->first;

			x /= 2;

			while(x--)
				cnt1.push_back(itr->first);
		}

		for(int i=0;i<m/2;i++)
		{
			for(int j=0;j<n;j++)
			{
				a[j][i] = a[j][m-i-1] = cnt1.back();
				cnt1.pop_back();
			}
		}

		while(id < n && m%2)
		{
			a[id++][m/2] = cnt1.back();
			a[id++][m/2] = cnt1.back();
			cnt1.pop_back();
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
	}

	return 0;
}
