#include<bits/stdc++.h>
using namespace std;

void printArr(vector< vector<int> > &dp) {

    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

/* Returns the total number of subarrays a[i...j] such that a[i]*...*a[j] is divisible by mod */
long Total_Subarrays_Divisible_By(int mod, vector<int> &a)
{
	int n = a.size();
	vector< vector<int> > dp(n, vector<int>(mod, 0));

	/* DP[i][rem] dentoes the number of subarrays ending at 'i' with remainder 'rem' */

	dp[0][a[0]%mod]++;
	for(int i = 1; i < n; i++)
	{
		int current_rem = a[i]%mod;
		//cout << "***cur_rem:\n" << i << " "  << current_rem << "\n***\n";

		// A single element subarray
		dp[i][current_rem]++;

		for(int old_rem = 0; old_rem < mod; old_rem++)
		{
			int new_rem = (current_rem*old_rem)%mod;
            //cout << "***new_rem:\n" << i << " " << new_rem << "\n***\n";

			dp[i][new_rem] += dp[i-1][old_rem];
			//cout << "***old_rem:\n" << i-1 << " " << old_rem << "\n***\n";
		}
		//cout << endl;
		//printArr(dp);
		//cout << endl;
	}
	long res = 0;
	for(int i = 0; i < n; i++)
    {
        res = res + dp[i][0];
        //cout << "***res:\n" << res << "\n***\n";
    }

	return res;
}

void Squared_Subsequences(vector<int> &a)
{
	long n = a.size();
	long ans = Total_Subarrays_Divisible_By(4, a);
	ans += n*(n+1)/2 - Total_Subarrays_Divisible_By(2, a);

	cout << ans << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
	int t;
	cin >> t;

	for(int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] = abs(a[i]);
        }

		Squared_Subsequences(a);
	}
	return 0;
}






















//#include <bits/stdc++.h>
//using namespace std;
//
//bool seq(int x) {
//
//    for (int i = 0; i <= x; i++)
//    {
//        for (int j = 0; j < i; j++) {
//            int res = i*i - j*j;
//            if (x == res)
//            {
//                cout << i << " " << j << endl;
//                return true;
//            }
//        }
//    }
//
//    return false;
//}
//
//int main()
//{
//   // freopen("input.txt", "r", stdin);
//    int t;
//    cin >> t;
//    while (t--) {
//
//        int N;
//        cin >> N;
//
//        int arr[N];
//        set<int> sub;
//
//        for (int i = 0; i < N; i++) {
//            int x;
//            cin >> x;
//            arr[i] = x;
//            sub.insert(arr[i]);
//
////            if (seq(x) == true) {
////                cout << x << endl;
////            }
//
//        }
//        //int n = fact (N);
//        for (int i = 0; i < N-1; i++)
//        {
//            for (int j = i+1; j < N; j++){
//                int res;
//                res = arr[i]*arr[j];
//                sub.insert(res);
//            }
//        }
////        for (int i = 0; i < n; i++) {
////            cout << sub[i] << " ";
////        }
//        int c = 0;
//        set<int>::iterator it;
//        for (it = sub.begin(); it != sub.end(); ++it) {
//            if (seq(*it)) {
//                c++;
//            }
//        }
//        cout << c << endl;
//
//    }
//    return 0;
//}
