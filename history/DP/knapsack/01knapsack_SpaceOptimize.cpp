#include <bits/stdc++.h>
#define ilovekanade ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main(){
    int n, limit; cin >> n >> limit;
    vector<int> w(n), v(n), dp(limit+5, 0);
    for(int i = 0;i < n;i++) cin >> v[i] >> w[i];
    for(int i = 0;i < n;i++){
        for(int j = limit;j - w[i]>= 0; j--){
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }
    cout << dp[limit];
}