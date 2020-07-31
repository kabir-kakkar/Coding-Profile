#include <bits/stdc++.h>
using namespace std;

void column_name (int n) {
    char str[50];
    int i = 0;
    while (n > 0) {
        int rem = n%26;

        if (rem == 0) {
            str[i] = 'Z';
            n = n/26 - 1;
        } else {
            str[i] = (rem - 1) + 'A';
            n /= 26;
        }
        ++i;
    }
    // /0 lets the library know that this is where the string will end
    str[i] = '\0';
    reverse (str, str + i);
    cout << str << endl;
    return;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        column_name(n);
    }

    return 0;
}
