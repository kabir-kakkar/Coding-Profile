#include <bits/stdc++.h>
using namespace std;

int main()
{
//    //add these line in your code
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//


    int a, b, c;
  	int n = 3;
    int sum = 0;
 	cin >> a >> b;

  	for (int i=0; i<n; i++)
    {
      cin >> c;
      if ((a+b)/c != 0)
      {  sum++;  }
      cout << sum << "\n";
    }
	return 0;
}
