// C++ implementation of the above approach

#include <bits/stdc++.h>
using namespace std;

const int maxn = 16;

// Function to generate the dp array
vector<int> precompute()
{
    vector<int> dp(maxn, -1);
    dp[0] = 0;

    for (int i = 1; i < maxn; ++i) {

        // combination of three integers
        for (auto j : vector<int>{ 4, 6, 9 }) {

            // take the maxium number of summands
            if (i >= j && dp[i - j] != -1) {
                dp[i] = max(dp[i], dp[i - j] + 1);
            }
        }
    }

    return dp;
}

// Function to find the maximum number of summands
int Maximum_Summands(vector<int> dp, int n)
{
    // If n is a smaller number, less than 16
    // return dp[n]
    if (n < maxn)
        return dp[n];

    else {

        // Else, find a minimal number t
        // as explained in solution
        int t = (n - maxn) / 4 + 1;
        return t + dp[n - 4 * t];
    }
}

// Driver code
int main()
{
    int n = 12;

    // Generate dp array
    vector<int> dp = precompute();

    cout << Maximum_Summands(dp, n) << endl;

    return 0;
}
