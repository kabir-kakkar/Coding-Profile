#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int max = 0, cnt = 0;

   while (n > 0) {
        if (n%2 == 1) {
            cnt++;
            if (cnt > max)
                max = cnt;
        } else {
            cnt = 0;
        }
        n/=2;
    }

    cout << max << '\n';

    return 0;
}
