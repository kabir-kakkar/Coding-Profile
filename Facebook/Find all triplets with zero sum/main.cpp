// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

bool findTriplets(int arr[], int n);

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
        if(findTriplets(arr, n))
        cout<<"1"<<endl;
        else
        cout<<"0"<<endl;
	}
    return 0;
}// } Driver Code Ends

// function to print triplets with 0 sum
bool findTriplets(int arr[], int n)
{
	for (int i=0; i<n-1; i++)
	{
		unordered_set<int> s;
		for (int j=i+1; j<n; j++)
		{
		    int x = -(arr[i] + arr[j]);
            if (s.find(x) != s.end())
            {
                return true;
            }
            else
                s.insert(arr[j]);
		}
	}

	return false;
}
