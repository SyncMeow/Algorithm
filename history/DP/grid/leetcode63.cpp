#include <bits/stdc++.h>
#define ilovekanade ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(obstacleGrid[i-1][j-1] == 0) dp[i][j] = (i*j==1)? 1: dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m][n];
}

int main(){
    vector<vector<int>> a = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << uniquePathsWithObstacles(a);
}