#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

string color[200005];
map<string, int> mp; 

int main(){
    fastio
    int m, n; cin >> m >> n;

    for(int i = 0;i < n;i++){
        cin >> color[i];
        if (i < m)mp[color[i]]++;
    }

    int l = 0, r = m-1, ans = 0;
    while(l < n && r < n){
        if (mp.size() == m) ans++;
        mp[color[l]]--;
        if (mp[color[l]] == 0) mp.erase(color[l]);
        l++;
        r++;
        mp[color[r]]++;
        
    }
    cout << ans << '\n';
}