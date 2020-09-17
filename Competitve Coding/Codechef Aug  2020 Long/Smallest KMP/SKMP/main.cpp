#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        string s, p;
        cin >> s >> p;

        int freqs[26], freqp[26];

        memset (freqp, 0, sizeof(freqp));
        memset (freqs, 0, sizeof(freqs));

        // Creating freq Array
        for (int i = 0; i < s.length(); i++) {
            freqs [ s[i] - 97 ] += 1;
        }
        for (int i = 0; i < p.length(); i++){
            freqp [ p[i] - 97 ] += 1;
        }

        // Remove characters matching in string s and string p
        for (int k = 0; k < 26; k++) {
            freqs[k] = freqs[k] - freqp[k];
        }

        // Create A sorted string
        string str = "";
        // For all alphabetical digit
        for (int k = 0; k < 26; k++) {
            // For how many times that character is occurring
            for (int q = 0; q < freqs[k]; q++) {
                // Convert the Integer into Character
                char ch = k + 97;
                // Append the character received to the string
                str += ch;
            }
        }

        int i, k = 0, j = 0, flag = 0, flag1 = 0;
        string ans, ans1;

        for (i = 0; i < str.length(); i++) {
            if ( p[0] == str[i] && flag == 0 ) {
                ans1 += str.substr(0, i) + p;
                flag = 1;
                k = i;
            } else if ( p[0] < str[i] && flag1 == 0) {
                ans += str.substr (0, i) + p;
                flag1 = 1;
                j = i;
            }
        }

        string final_ans;
        if (flag1 == 1 && flag == 1) {
            // The Less than Operator Does a Lexicographical comparison on the strings
            if (ans < ans1) {
                final_ans = ans + str.substr(j, str.length() - j);
            } else {
                final_ans = ans1 + str.substr(k, str.length() - k);
            }
        } else if (flag1 == 1) {
            final_ans = ans + str.substr(j, str.length() - j);
        } else if (flag == 1) {
            final_ans = ans1 + str.substr(k, str.length() - k);
        } else {
            final_ans = str + p;
        }
        cout << final_ans << "\n";
    }
}


// Initial Approach
//bool lexagorical (char s, char p)
//{
//    if (s <= p)
//        return true;
//    return false;
//}
//
//bool findCharAndRemove (char s, string &p) {
//    for (int i = 0; i < p.length(); i++) {
//        if (p[i] == s) {
//            p[i] = ' ';
//            return true;
//        }
//    }
//    return false;
//}
//
//int main()
//{
//    freopen("input.txt", "r", stdin);
//    int t;
//    cin >> t;
//
//    while (t--) {
//        string s, p;
//        cin >> s >> p;
//
//            string temp = p;
//            int n = s.length();
//
//            // Find Chars which have pattern p
//            for (int i = 0; i < n; i++) {
//                if (findCharAndRemove(s[i], temp)) {
//                   s[i] = ' ';
//                }
//            }
//
//            char te;
//            // Arrange String S lexagorically
//            for(int i = 0; i < s.length()-1; ++i) {
//               for( int j = i+1; j < s.length(); ++j)
//               {
//                  if(s[i] > s[j])
//                  {
//                    te = s[i];
//                    s[i] = s[j];
//                    s[j] = te;
//                  }
//                }
//            }
//
//
//            // Erase blank space
//            int i = 0;
//            while (s[i] == ' ') {
//                i++;
//            }
//            s.erase(0, i);
//
//            for (i = 0; i < s.length(); i++) {
//                if (s[i] <= p[0]  && p[0] < s[i+1] && i != s.length()-1) {
//                    s.insert(i+1, p);
//                    break;
//                }
//            }
//            cout << s << endl;
//    }
//}
