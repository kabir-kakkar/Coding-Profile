#include <bits/stdc++.h>
using namespace std;

struct Points {
    int x, y;
};

bool doOverlap (Points l1, Points r1, Points l2, Points r2) {

    // Here we check for the cases in which overlapping is not possible
    // Two such cases are there where one rectangle is on left of other
    // And one is on top of other
    // if it's neither then we can say that the rectangles overlap

    // If one rectangle is on left side of other
    if (l1.x > r2.x || l2.x > r1.x)
        return false;

    // If one rectangle is on top of other
    if (r2.y > l1.y || r1.y > l2.y)
        return false;

    // The Case where all the above statements are false and hence the rectangles overlap
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
         Points l1, r1, l2, r2;

        // First Rectangle top left corner
        cin >> l1.x >> l1.y;
        // First Rectangle bottom right corner
        cin >> r1.x >> r1.y;

        // Second Rectangle top left corner
        cin >> l2.x >> l2.y;
        // Second Rectangle bottom right corner
        cin >> r2.x >> r2.y;


        cout << doOverlap(l1, r1, l2, r2) << endl;
    }

    return 0;
}
