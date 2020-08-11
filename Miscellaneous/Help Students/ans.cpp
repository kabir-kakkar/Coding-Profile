// { Driver Code Starts


//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


//User function Template for C++

vector<int> help_classmate(vector<int> a, int n) 
{ 
    // code here 
    int i, j;
    bool flag = true;
    vector<int> result;
    
    for (i = 0; i < n; i++)
    {
        flag = true;
        for (j = i+1; j < n; j++)
        {
            if ( a[j] < a[i] )
            {
                flag = false;
                result.push_back(a[j]);
                break;
            }
        }
        if (flag) {
            result.push_back(-1);
        }
    }
    return result;
} 

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>array[i];
        }
        vector<int> result = help_classmate(array,n);
        for (int i = 0; i < n; ++i)
        {
            cout<<result[i]<<" ";
        }
        cout<<"\n";
    }
    return 0; 
}
  // } Driver Code Ends