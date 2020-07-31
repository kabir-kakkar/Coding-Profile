// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string multiplyStrings(string , string );

int main() {

    freopen("input.txt", "r", stdin);

    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;

    	cout<<multiplyStrings(a,b)<<endl;
    }

}// } Driver Code Ends


/*You are required to complete below function */
string multiplyStrings(string s1, string s2) {

   //Your code here

   if (s1.at(0) == '0' && s1.size() == 1) {
       return "0";
   }
   if (s2.at(0) == '0' && s2.size() == 1) {
       return "0";
   }

    if ((s1.at(0) == '-' && s2.at(0) != '-') || (s1.at(0) != '-' && s2.at(0) == '-'))
     cout << "-";

    if (s1.at(0) == '-' && s2.at(0) != '-')
        s1 = s1.substr(1);
    else if (s1.at(0) != '-' && s2.at(0) == '-')
        s2 = s2.substr(1);
    else if (s1.at(0) == '-' && s2.at(0) == '-') {
        s1 = s1.substr(1);
        s2 = s2.substr(1);
    }

   int len1 = s1.size();
   int len2 = s2.size();

   if (len1 == 0 || len2 == 0)
        return "0";

    vector<int> result (len1+len2, 0);
    int i_n1=0;
    int i_n2=0;

    for(int i = len1-1; i >= 0; i--) {
        int carry = 0;
        int n1 = s1[i] - '0';

        i_n2=0;
        for(int j = len2-1; j >= 0; j--) {
            int n2 = s2[j] - '0';
            int sum = n1*n2 + result[i_n1+i_n2] + carry;

            carry = sum/10;

            result[i_n1 + i_n2] = sum%10;

            i_n2++;
        }
        if (carry>0)
            result[i_n1 + i_n2] += carry;

        i_n1++;
    }
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;

    if (i==-1)
        return "0";

    string s = "";
    while (i >= 0)
        s += std::to_string (result[i--]);

    return s;
}
