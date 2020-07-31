#include <bits/stdc++.h>
using namespace std;

void fastscan(long long &number)
{
    register long long c;

    number = 0;

    // extract current character from buffer
    c = getchar();

    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // value of the input number
}
int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie (NULL);

	long long T;
	fastscan(T);
	while(T--)
	{
		long long n;
		    fastscan(n);
		long long a[n],b[n],c1=0,c2=0;
		for(int i=0;i<n;i++)
		    fastscan(a[i]);
		for(int i=0;i<n;i++)
		    fastscan(b[i]);

		int q,p;

		for(int i=0; i<n; i++)
		{
			p=i-a[i];
			if(p<0)
			    p=0;
			q= i+a[i];
			if(q>=n)
			    q=n-1;
		    c1 += q-p;
		    c2 += b[i];
		    cout << c1 << "\t" << c2 << "\n";
		}

		if(c1+n == c2)
		    cout<<"YES\n";
		else
		    cout<<"NO\n";
	}
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    freopen ("input.txt", "r", stdin);
//
//    int T;
//    cin >> T;
//
//    while (T--)
//    {
//        long long i, j;
//        long long N; // Total number of caves
//        cin >> N;
//        int A[N] = {}; // Radiation Power
//        int C[N];
//        for (i = 0; i < N; i++)
//        {
//            cin >> C[i];
//
//            int a = i - C[i];
//            int b = i + C[i];
//
//            if (a < 0)
//                a = 0;
//            if (b > N)
//                b = N;
//
//            for (j = a; j <= b; j++)
//            {
//                A[j] += 1;
//            }
//        }
//        int Z[N];
//        for (i = 0; i < N; i++)
//        {
//            cin >> Z[i];
//        }
//        bool flag = true;
//        for (i = 0; i < N; i++)
//        {
//            if (A[i] < Z[i])
//            {
//                flag = false;
//                break;
//            }
//        }
//
//        if (flag)
//            cout << "YES\n";
//        else
//            cout << "NO\n";
//    }
//
//    return 0;
//}
