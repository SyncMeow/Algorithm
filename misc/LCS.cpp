#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void LCS(string &a,string &b){
    int n = a.size(), m = b.size();

    int dp[150][150] = {0};

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m] << '\n';
}

int main(){
    fastio
    string a, b;
    while(cin >> a >> b) LCS(a, b);
}