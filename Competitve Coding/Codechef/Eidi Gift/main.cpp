#include <bits/stdc++.h>
using namespace std;

void fastscan(int &number)
{
    bool negative = false;
    register int c;

    number = 0;
    c = getchar();

    if (c=='-')
    {
        negative = true;
        c = getchar();
    }

    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int T;
    fastscan(T);

    while (T--)
    {
        int A[3] = {}, C[3] = {};
        int i, j;

        for (i = 0; i < 3; i++)
            fastscan(A[i]);
        for (i = 0; i < 3; i++)
            fastscan(C[i]);

        bool flag = true;
        for (i = 0; i < 3; i++)
        {
            for (j = i+1; j < 3; j++)
            {
               if ( (A[j] > A[i] && C[j] <= C[i]) || (A[j]==A[i] && C[j] != C[i]) || (A[j] < A[i] && C[j] >= C[i]))
               {
                    flag = false;
                    break;
               }
            }
            if (!flag)
                break;
        }

        if (flag)
            cout << "FAIR\n";
        else
            cout << "NOT FAIR\n";
    }
}
