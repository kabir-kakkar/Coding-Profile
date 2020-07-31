#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);

    long long n, i;
    cin >> n;

    string name;
    long long no;

    map<string, long long> num_book;

    for (i = 0; i < n; i++)
    {
        cin >> name >> no;
        num_book.insert(pair <string, long long> (name, no));
    }

    for (i = 0; i < n; i++)
    {
        cin >> name;

        if (num_book.find (name) != num_book.end()) {
            cout << name << "=" << num_book[name] << "\n";
        }
        else {
            cout << "Not found\n";
        }
    }

    return 0;
}
