#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    while (T--) {
        int N, M, X, Y;
        cin >> N >> M >> X >> Y;

        int total = N * X + M * Y;
        int flag = false;

        for (int i = 0; i <=N; i++)
        {
            for (int j = 0; j <= M; j++)
            {
                int elf1 = i*X + j*Y;
                int elf2 = total - elf1;

                if (elf1 == elf2) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        flag ? cout << "YES\n" : cout << "NO\n";
    }
}
