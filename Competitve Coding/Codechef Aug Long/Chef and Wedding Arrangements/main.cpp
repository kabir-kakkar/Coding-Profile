#include <bits/stdc++.h>
using namespace std;

void printArr (int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int cnt[101], dp[1005], f[1005];

        for (int i = 0; i < n; i++)
            cin >> f[i];

        // Initialize the value of dp to max value
        for (int i = 0; i <= n; i++)
            dp[i] = 1e9;

        // If no person is present on the table the answer will be zero
        // This case refers to 0 table
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            //Set Frequency Array to Zero
            memset (cnt, 0, sizeof cnt);


            for (int j = i; j < n; j++) {
                    // Increase the count of that number in the frequency array
                    cnt[ f[j] ]++;

                    // This g value will hold the number of arguments present in the current
                    // arrangement
                    int g = 0;

                    for (int p = 1; p <= 100; p++) {
                        // This is the case for a conflict
                        if ( cnt[p] > 1 ) {
                            g += cnt[p];
                        }
                    }

                    // We will have to store the minimum value
                    // in an array
                    dp [ j+1 ]  =  min ( dp[i] + g + k,  dp[j+1] );

//                    cout << i << " " << j << " " << endl;
//                    cout << "\t";
//                    printArr(cnt, n+1);
//                    cout << "\t\tDP:";
//                    printArr(dp, n+1);

                    // In the first iteration, the above code will not have any min value stored
                    // In Second iteration and onwards, we will be checking if this array has a min value
                    // Then we will compare to the new set of tables created
                    // Finally, we compare the minimum value and put the minimum value in place of dp[j+1]

                    // Hence in the last iteration, j+1 = n, and dp[n] will hold the minimum value
            }
        }
        cout << dp[n] << endl;
    }
}
