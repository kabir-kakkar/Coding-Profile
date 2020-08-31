#include <bits/stdc++.h>
using namespace std;

#define N 101
#define M 101

void floodFill (int a[][M], int x, int y, int m, int n, int prevColor, int newColor) {
    
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    if (a[x][y] != prevColor)
        return;
    if (a[x][y] == newColor)
        return;
    
    a[x][y] = newColor;
    
    floodFill (a, x+1, y, m, n, prevColor, newColor);
    
    floodFill (a, x-1, y, m, n, prevColor, newColor);
    
    floodFill (a, x, y+1, m, n, prevColor, newColor);
    
    floodFill (a, x, y-1, m, n, prevColor, newColor);
    
}

int main() {
	
	int t;
	cin >> t;
	
	while (t--) {
	    int n, m;
	    cin >>n >> m;
	    
	    int a[N][M] = {0};
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < m; j++) {
	            cin >> a[i][j];
	        }
	    }
	    
	   int x, y, newColor, prevColor;
	   cin >> x >> y >> newColor;
	   
	   prevColor = a[x][y];
	   floodFill (a, x, y, m, n, prevColor, newColor);
	   
	   for (int i = 0; i < n; i++)
	   {
	       for (int j = 0; j < m; j++)
	       {
	           cout << a[i][j] << " ";
	       }
	   }
	   cout << "\n";
	}
	
	return 0;
}