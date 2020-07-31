#include<bits/stdc++.h>
using namespace std;

int main () {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--) {
        bool ultimate_flag = false;

        int x, i, j;
        cin >> x;

        string dictonary[x];
        for (i = 0; i < x; i++) {
            cin >> dictonary[i];
        }

        int n, m;
        cin >> n >> m;

        char a;
        map<char, int> ma;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> a;
                ma[a]++;
            }
        }
        set<string> sorted_ans;

        for (string temp : dictonary) {
            map<char, int> t = ma;
            bool flag = true;
            map<char, int>::iterator it ;
            for (char c : temp) {
                it = t.find(c);
                if (it == t.end()) {
                    flag = false;
                    break;
                } else {
                    if (it->second >= 1) {
                        it->second = it->second - 1;
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                sorted_ans.insert(temp);
                ultimate_flag = true;
            }
        }
        if (ultimate_flag) {
                for (string temp: sorted_ans) {
                    cout << temp << " ";
                }
        } else {
            cout << "-1";
        }
        cout << endl;
    }
}

//#include <bits/stdc++.h>
//using namespace std;
//
//int n, m, x;
//char boggle[10][10];
//string dictonary[12];
//
//bool flag = false;
//
//bool isWord(string &str) {
//    for (int i = 0; i < x; i++)
//        if (str.compare(dictonary[i]) == 0)
//            return true;
//    return false;
//}
//
//void findWordsUtil (bool visited[][10], int i, int j, string &str) {
//    visited[i][j] = true;
//    str = str + boggle[i][j];
//
//    if (isWord(str)) {
//            flag = true;
//            cout << str << endl;
//    }
//
//    for (int row = i-1; row <= i+1 && row<n; row++) {
//        for (int col = j-1; col <= j+1 && col<m; col++) {
//            if (row >= 0 && col >= 0 && !visited[row][col]) {
//                findWordsUtil (visited, row, col, str);
//            }
//        }
//    }
//
//    str.erase(str.length() - 1);
//	visited[i][j] = false;
//}
//
//int main() {
//   freopen("input.txt", "r", stdin);
//
//    int t;
//    cin >> t;
//
//    while (t--) {
//        int i, j;
//        cin >> x;
//
//
//        for (i = 0; i < x; i++) {
//            cin >> dictonary[i];
//        }
//
//        cin >> n >> m;
//
//        for (i = 0; i < n; i++) {
//            for (j = 0; j < m; j++) {
//                cin >> boggle[i][j];
//            }
//        }
//
//        bool visited[10][10] = {{false}};
//        string str = "";
//
//        for (i = 0; i < n; i++) {
//            for (j = 0; j < m; j++) {
//                findWordsUtil (visited, i, j, str);
//            }
//        }
//
//        if (!flag)
//            cout << "-1\n";
//        flag = false;
//    }
//
//    return 0;
//}
