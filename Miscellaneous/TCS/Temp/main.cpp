#include <bits/stdc++.h>
using namespace std;

// Function that convert Decimal to binary
int decToBinary_One(int n)
{
    int one_ = 0, zero_ = 0;
    // Size of an integer is assumed to be 32 bits
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            one_ += 1;
        else
            zero_ += 0;
    }
    return one_;
}

// Function that convert Decimal to binary
int decToBinary_Zero(int n)
{
    int one_ = 0, zero_ = 0;
    // Size of an integer is assumed to be 32 bits
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            one_ += 1;
        else
            zero_ += 0;
    }
    return zero_;
}


int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int one_ = decToBinary_One(a[i]);
    }
    return 0;
}
