#include <bits/stdc++.h>
#define ilovekanade ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main(){
    ilovekanade
    int n, limit, dp[200][300]; cin >> n >> limit;

    vector<int> w(n), v(n);
    
    for(int i = 0;i < n;i++) cin >> w[i] >> v[i];

    for(int i = 0;i < n;i++){
        for(int j = 0;j <= limit; j++){
            if(j < w[i]) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j], v[i] + dp[i][j-w[i]]);
        }
    }

    cout << dp[n][limit];
}
