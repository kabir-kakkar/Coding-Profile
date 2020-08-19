

#include <bits/stdc++.h>
using namespace std;

int count_vowels (string s)
{
    int c = 0, vowel = 0;
    while (s[c] != '\0') {
        if (s[c] == 'a' || s[c] == 'e' || s[c] == 'i' || s[c] =='o' || s[c] == 'u')
            vowel++;
        c++;
    }
    return vowel;
}

int getPairsCount(int a[], int n, int vowel)
{
    int c = 0;

    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if (a[i]+a[j] == vowel)
                c++;

    return c;
}

string one[] = { "", "one", "two", "three", "four",
                 "five", "six", "seven", "eight",
                 "nine", "ten", "eleven", "twelve",
                 "thirteen", "fourteen", "fifteen",
                 "sixteen", "seventeen", "eighteen",
                 "nineteen" };

string ten[] = { "", "", "twenty ", "thirty ", "forty ",
                 "fifty ", "sixty ", "seventy ", "eighty ",
                 "ninety " };

string num_to_words(int n, string s)
{
    string str = "";
    if (n > 19)
        str += ten[n / 10] + one[n % 10];
    else
        str += one[n];

    if (n)
        str += s;

    return str;
}

string convert_to_words(int n)
{
    if (n == 0) {
        return "zero";
    }
    if (n == 100) {
        return "hundred";
    }

    string out;

    out += num_to_words((n % 100), "");

    return out;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    int vowel=0;
    int a[n];
    for (int i = 0; i < n; i++) {
            cin >> a[i];
            string s;
            s = convert_to_words(a[i]);
            vowel += count_vowels(s);
    }
    int ans = getPairsCount(a, n, vowel);
    if (ans > 100) {
        cout << "greater 100";
    } else {
        cout << convert_to_words(ans);
    }
}
