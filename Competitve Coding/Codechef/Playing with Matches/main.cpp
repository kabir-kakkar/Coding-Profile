#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, sum = 0, matches = 0, temp = 0;

        cin >> a >> b;
        sum = a + b;

        while (sum != 0)
        {
            temp = sum%10;
            sum /= 10;

            if (temp == 0)
                matches += 6;
            else if (temp == 1)
                matches += 2;
            else if (temp == 2)
                matches += 5;
            else if (temp == 3)
                matches += 5;
            else if (temp == 4)
                matches += 4;
            else if (temp == 5)
                matches += 5;
            else if (temp == 6)
                matches += 6;
            else if (temp == 7)
                matches += 3;
            else if (temp == 8)
                matches += 7;
            else if (temp == 9)
                matches += 6;
        }
        cout << matches << "\n";
    }

    return 0;
}
