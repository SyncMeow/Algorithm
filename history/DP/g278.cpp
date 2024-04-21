#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fastio
    int n, k; cin >> n >> k;
    vector<int> food(n), last(n, 0), left(n, 0); 
    for(int i = 0;i < n;i++){
        cin >> food[i];
    }

    last[food[0]] = 0;
    for(int i = 1;i < n;i++){
        left[i] = max(left[i-1], last[food[i]]+1);
        last[food[i]] = i;
    }

    vector<vector<int>> dp(1e6+5, vector<int>(25, 0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= k;j++){
            if (i*j!=0){
                dp[i][j] = max(dp[i-1][j], dp[left[i]-1][j-1] + i-left[i]+1);
            } 
        }
    }

    cout << dp[n-1][k] << '\n';
}