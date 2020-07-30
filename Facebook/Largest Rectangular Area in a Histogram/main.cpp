#include <bits/stdc++.h>
using namespace std;

int getMaxArea (int hist[], int n) {
    stack<int> s;

    int max_area = 0;
    int tp;
    int area_with_top;

    int i = 0;
    while (i < n) {

        if (s.empty() || hist[i] >= hist[s.top()])
            s.push(i++);

        else
        {
            tp = s.top();
            s.pop();

            // Area with hist[tp] stack as smallest bar
            // It is calculated as right index (i) - left index {s.top() - 1)
            // Multiplied by the height of the histogram
            area_with_top = hist[tp] * ( s.empty() ? i : i - s.top() - 1 );

            if ( max_area < area_with_top )
                max_area = area_with_top;
        }
    }

    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }
    return max_area;
}

int main()
{
    freopen ("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << getMaxArea(a, n) << endl;
    }

    return 0;
}
