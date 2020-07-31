#include <bits/stdc++.h>
using namespace std;

int s[1000][1000] = {0};

int Matrix_Chain_Multiplication (int p[], int n) {
    int m[n][n];


    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;


    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j-1; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n-1];
}

int main()
{
    //3 Matrix with dimensions 1x2, 2x3, 3x4
    int arr[] = {5, 4, 6, 2, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    int m = Matrix_Chain_Multiplication(arr, n);
    cout << m << "\n";

    for (int i = 1; i < n-1; i++) {
        for (int j = 2; j < n; j++) {
            cout << s[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
