#include <bits/stdc++.h>
using namespace std;

// code chef problem : MSNSADM1

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);

    int Testcases = 0;
    int n;
    int A[50];
    int B[50];
    int totalScore[50];

    int i, maximum_score;

    cin >> Testcases;

    while (Testcases--)
    {
        cin >> n;

        for (i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        for (i = 0; i < n; i++)
        {
            cin >> B[i];
        }

        for (i = 0; i < n; i++)
        {
            totalScore[i] = (A[i] * 20) - (B[i] * 10);
        }

        maximum_score = 0;
        for (i = 0; i < n; i++)
        {
            if (maximum_score < totalScore[i])
                maximum_score = totalScore[i];
        }

        if (maximum_score <= 0)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << maximum_score << "\n";
        }
    }
}
