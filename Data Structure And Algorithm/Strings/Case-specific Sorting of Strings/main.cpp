#include<bits/stdc++.h>
using namespace std;


string caseSort(string str, int n){
    int a[n];
    string ls, us;
   
    for (int i = 0; i < n; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            ls.push_back(str[i]);
          
            a[i] = 0;
        } else {
            us.push_back(str[i]);
        
            a[i] = 1;
        }
    }
    
    sort (ls.begin(), ls.end());
    sort (us.begin(), us.end());
    
    int k = 0, j = 0;
    
    string new_str;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            new_str.push_back(ls[k++]);
        } else {
            new_str.push_back(us[j++]);
        }
    }
    
    return new_str;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		
		cout<<caseSort (str, n)<<endl;
	}
} 