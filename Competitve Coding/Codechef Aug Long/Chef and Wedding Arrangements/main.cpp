#include <bits/stdc++.h>
using namespace std;

int calcCost (int a[], int st, int end, int k)
{
    int i, j;
    int cost = k;
    for (i = st; i < end; i++) {
        for (j = i+1; j <= end; j++) {
            if (a[i] == a[j]) {
                cost++;
            }
        }
    }
    return cost;
}

// Driver code
int main()
{
	int arr[] = { 5, 1, 3, 3, 3 };
	int n = sizeof(arr) / sizeof(int);
	int cost = 1;

	int i, j, k, L, q;
    int m[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}
