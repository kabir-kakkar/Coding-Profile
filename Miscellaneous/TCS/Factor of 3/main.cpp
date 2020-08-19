// C++ program to display all permutations
// of an array using STL in C++

#include <bits/stdc++.h>
using namespace std;

void display (int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Driver code
int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        bool flag = true;

        while (next_permutation(a, a + n) && flag) {
                //check if complete array satisfies the condition
                for (int i = 0; i < n-1; i++) {
                    if ( a[i]%3 == 0 && a[i+1]%3 == 0) {
                        flag = true;
                        break;
                    } else {
                        flag = false;
                        //display(a, n);
                    }
                }
        }

            if (!flag)
                cout << "Yes\n";
            else
                cout << "No\n";
    }

    return 0;
}
