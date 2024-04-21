#include <bits/stdc++.h>
#define cock ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main(){
    cock
    int n, m, k; cin >> n >> m >> k;
    vector<int> app(n), apart(m);
    for(int i = 0;i < n;i++) cin >> app[i];
    for(int i = 0;i < m;i++) cin >> apart[i];
    sort(app.begin(), app.end());
    sort(apart.begin(), apart.end());

    int l = 0, r = 0, cnt = 0;
    while(l < n && r < m){
        if (abs(app[l] - apart[r]) <= k){
            l++;
            r++;
            cnt++;
        }else{
            if (app[l] - apart[r] > k) r++;
            else l++;
        }
    }

    cout << cnt;
}