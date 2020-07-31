#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

bool duration_of_activity (Activity a1, Activity a2) {
    return (a1.finish < a2.finish);
}

void swap (Activity *a1, Activity *a2) {
    Activity t = *a1;
    *a1 = *a2;
    *a2 = t;
}

int partition (Activity arr[], int low, int high) {
    Activity pivot = arr[high];
    int i = (low-1);

    for (int j = low; j <= high-1; j++) {
        if (duration_of_activity(arr[j], pivot)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort (Activity arr[], int low, int high) {
    if (low < high)
    {
        int pi = partition (arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
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

      //  sort(arr, arr+n, duration_of_activity);
      quickSort (arr, 0, n-1);

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
