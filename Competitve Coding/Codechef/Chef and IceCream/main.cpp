#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        int temp=0, five=0, ten=0, fifteen=0;
        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            cin >> temp;

            if (temp == 5) {
                five++;
            } else if (temp == 10) {
                if (five >= 1) {
                    ten++;
                    five--;
                } else {
                    flag = false;
                    break;
                }
            } else if (temp == 15) {
                if (ten >= 1) {
                    fifteen++;
                    ten--;
                } else if ( five >= 2 ) {
                    fifteen++;
                    five -= 2;
                } else {
                    flag = false;
                    break;
                }
            }
        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";

        cout << "\nFive\t" << five << endl;
        cout << "Ten\t" << ten << endl;
        cout << "Fift\t" << fifteen << endl;

        cout << "\n***\n";
    }
	return 0;
}
