#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int test;
    cin >> test;
    
    while (test--) {
        int n;
        cin >> n;
        
        int v[n];
        for (int i = 0; i < n; i++)
            cin >> v[i];
            
        int best =  n, worst = 0;
        
        // Key -> t(time), v(speed)
        // Value -> the athletes no.
        map<  pair<int, int>, vector<int> >mp;
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (v[i] > v[j]) {
                    int t = ( ( j - i ) * 120)/( v[i] - v[j]);
                    int x = i * 120 + v[i] * t;
                    mp[make_pair(t,x)].push_back(i);
                    mp[make_pair(t,x)].push_back(j);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            vector<bool> infected(n);
            infected[i] = true;
            
            // Check if two athletes are at the same value of t and x
            // ie., at the same position and time
            // then we will make that athlete infected and move on to the second loop
            for (auto p: mp) {
                bool spread = false;
                for (int x:p.second) {
                    if (infected[x] == true)
                        spread = true;
                }
                if (spread == true) {
                    for (int x:p.second) {
                        infected[x] = true;
                    }
                }
            }
            
            int cnt = 0;
            for (int x:infected) {
                cnt += x;
            }
            best = min (best, cnt);
            worst = max (worst, cnt);
        }
        cout << best << " " << worst << endl;
    }
    
	return 0;
}
