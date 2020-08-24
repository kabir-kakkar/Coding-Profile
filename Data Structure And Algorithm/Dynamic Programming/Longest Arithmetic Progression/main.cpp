#include <iostream>
using namespace std;

#define MAX 90

void printArr (int a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Returns length of the longest AP subset in a given set
int lenghtOfLongestAP (int a[], int n) {

	if (n <= 2)
        return n;

	// Create a table and initialize all values as 2. The value of
	// L[i][j] stores LLAP with set[i] and set[j] as first two
	// elements of AP. Only valid entries are the entries where j>i
	int L[n][n] = {0};
	int llap = 2; // Initialize the result

	// Fill entries in last column as 2. There will always be
	// two elements in AP with last number of set as second
	// element in AP
	for (int i = 0; i < n; i++)
		L[i][n-1] = 2;

	// Consider every element as second element of AP
	for (int j=n-2; j>=1; j--) {
		// Search for i and k for j
		int i = j-1, k = j+1;
		while (i >= 0 && k <= n-1) {
            if (a[i] + a[k] < 2*a[j]) {
                    k++;
            }

            // Before changing i, set L[i][j] as 2
            else if (a[i] + a[k] > 2*a[j]) {
                L[i][j] = 2,
                i--;
            }

            else {
                // Found i and k for j, LLAP with i and j as first two
                // elements is equal to LLAP with j and k as first two
                // elements plus 1. L[j][k] must have been filled
                // before as we run the loop from right side
                L[i][j] = L[j][k] + 1;

                cout << a[i] << " "<< a[j] << " "<< a[k] << endl;

                // Update overall LLAP, if needed
                llap = max(llap, L[i][j]);

                // Change i and k to fill more L[i][j] values for
                // current j
                i--; k++;
            }
		}

		// If the loop was stopped due to k becoming more than
		// n-1, set the remaining entities in column j as 2
		while (i >= 0) {
			L[i][j] = 2;
			i--;
		}
	}
	//printArr (L, 6);
	return llap;
}

/* Driver program to test above function*/
int main() {
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
	cout << lenghtOfLongestAP(a, n) << endl;

	return 0;
}
