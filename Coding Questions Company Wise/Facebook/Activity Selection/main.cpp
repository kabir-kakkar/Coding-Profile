#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

bool duration_of_activity (Activity a1, Activity a2) {
    return (a1.finish < a2.finish);
}

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--) {
        int n, i;
        cin >> n;

        Activity arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i].start;
        }
        for (i = 0; i < n; i++) {
            cin >> arr[i].finish;
        }

        sort(arr, arr+n, duration_of_activity);

        i=0;
        int cnt=1;

        for (int j=1; j<n; j++) {
            if (arr[j].start >= arr[i].finish) {
                 cnt++;
                 i = j;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
