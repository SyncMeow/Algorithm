//ZeroJudge b184
#include <bits/stdc++.h>
using namespace std;

const int limit = 100;

int main(){
	int n;
	while (cin >> n){
		int v[105], w[105], dp[105][105];
			for(int i=0;i<n;i++) cin >> w[i] >> v[i];

			memset(dp, 0, sizeof(dp));

			for(int i = 0; i < n; i++){
				for(int j = 0; j <= limit; j++){
					if (j < w[i]) dp[i+1][j] = dp[i][j];
					else{
						dp[i+1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
					}
				}
			}

			cout << dp[n][limit] << "\n";
	}
	
}
