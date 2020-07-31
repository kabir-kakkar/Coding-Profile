#include<bits/stdc++.h>
using namespace std;


/*
BRUTE FORCE
*/
//bool valid (string s, int start, int end) {
//    int i = start;
//    int j = (start+end)/2;
//    int mid = j;
//
//    while (i < mid && j < end) {
//        if ( s[i] != s[j] )
//            return false;
//        i++;
//        j++;
//    }
//    return true;
//}
//
//int main ()
//{
//    freopen("input.txt", "r", stdin);
//    int t;
//    cin >> t;
//
//    while (t--)
//    {
//        string s;
//        cin >> s;
//
//        int n = s.length();
//        int cnt = 0;
//        for (int i = 2; i <= n-2; i+=2)
//        {
//            if (valid (s, 0, i) && valid (s, i, n))
//                cnt++;
//        }
//        cout << cnt << endl;
//    }
//}
//


/*
This solution uses KMP algo and Hashing
*/
#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> v, int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
}

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j-1];
        }
        if (s[i] == s[j])
            j++;
        pi[i] = j;
        //printArr(pi, n);
    }
    return pi;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        if (s.length ()%2) {
            cout << "0\n";
            continue;
        }

        int n = s.length ();
        string d = s;
        reverse(d.begin(), d.end());

        vector<int> orig = prefix_function(s),
                    dup = prefix_function(d);

  //      printArr(orig, orig.size());
 //       printArr(dup, dup.size());

        int cnt = 0;
        for (int i = 1; i < n-1; i+=2) {
            if ( (i+1)%2==0 && (n-i-1)%2==0 ) {

                int flen = (i+1)/2,
                    seclen = (n-i - 1)/2;
      //          cout << "******\n" << flen << "\n**********\n"   << seclen << "\n*********\n";


                if (orig[i] >= flen && dup[n - i - 2] >= seclen ) {
                    // This means that we have found the place where orig's seq and dup's seq have similar seq after this point
                    int remfi = i+1 -orig[i],
                        remsec = n-i -1 -dup[n-i-2];


           //       cout << "******\n" << orig[i] << "\n**********\n"   << dup[n-i-2] << "\n*********\n";

                    if ( (i+1)%remfi || (n-i-1)%remsec )
                    {
                        continue;
                    }

                    int fir = (i+1)/remfi,
                        sec = (n-i - 1)/remsec;

                    if ( fir%2 == 0  && sec%2 == 0 )
                        cnt++;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
