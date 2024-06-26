#include <bits/stdc++.h>
#define ilovekanade ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 1; i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m][n];
}

int main(){
    ilovekanade
    string a, b; cin >> a >> b;
    cout << longestCommonSubsequence(a, b);
}