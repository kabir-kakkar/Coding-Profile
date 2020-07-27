#include <bits/stdc++.h>
using namespace std;

string convertToRoman (int n) {
    string romans[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int nums[]      = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    string res = "";
    for (int i = 12; i >= 0; i--) {
        while (n >= nums[i]) {
            res += romans[i];
            n -= nums[i];
        }
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cout << convertToRoman(n) << endl;
    }

    return 0;
}
