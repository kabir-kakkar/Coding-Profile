#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);

    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    while (T--)
    {
        char A[100000];
        cin >> A;

        int i = 0;
        int n = strlen(A);

        for (int j = 0; j < 100; j++)
        {
            for (i = 0; i < n; i++)
            {
                if (A[i] == '1')
                {
                    A[i] = 'N';

                    if (A[i+1] == '1')
                        A[i+1] = '0';
                    else if (A[i+1] == '0')
                        A[i+1] = '1';

                    if (A[i-1] == '1')
                        A[i-1] = '0';
                    else if (A[i-1] == '0')
                        A[i-1] = '1';
                }
            }
        }

        bool flag = true;
        for (i = 0; i < n; i++)
        {
            if (A[i] != 'N'){
                flag = false;
            }
        }

        if (flag)
            cout << "WIN" << "\n";
        else
            cout << "LOSE" << "\n";

        cout << A << "\n";
    }
}
