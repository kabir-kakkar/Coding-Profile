//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    ios_base::sync_with_stdio (false);
//    cin.tie (0);
//    cout.tie (0);
//
//   freopen("input.txt", "r", stdin);
//
//    int T;
//    cin >> T;
//
//    while (T--)
//    {
//        long long N, K;
//
//        cin >> N >> K;
//
//        long long temp1 = N, temp2 = N;
//        long long box1[K] = {};
//        long long box2[K] = {};
//        long long i, j;
//        bool flag = true;
//
//        int ch = 1;
//
//        while (temp1 > 0 && ch)
//        {
//            for (i = 0; i < K; i++)
//            {
//                box1[i] += 1;
//                temp1--;
//
//                for (j = 0; j < K; j++)
//                {
//                    if (temp2 > 0) {
//                        box2[i] += 1;
//                        temp2--;
//                    } else {
//                        break;
//                    }
//                }
//
//                if (temp2 < 0)
//                {
//                    ch = 0;
//                    break;
//                }
//
//                if (temp1 <= 0) {
//                    break;
//                }
//            }
//        }
//
//        for (i = 0; i < K; i++)
//        {
//            if (box1[i] != box2[i]) {
//                flag = false;
//                break;
//            }
//        }
//
//        if (flag)
//            cout << "NO\n";
//        else
//            cout << "YES\n";
//    }
//}

#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);

	int t;
	cin>>t;

	while(t--){
	    long long int n,k,r=0;
	    cin>>n>>k;
	    r=n/k;
	    if(r%k==0)
	        cout<<"NO"<<endl;
	   else
	    cout<<"YES"<<endl;

	}
	return 0;
}
