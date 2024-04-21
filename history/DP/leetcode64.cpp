#include <bits/stdc++.h>
using namespace std;

int main(){
	int p, q; cin >> p >> q;
	int arr[505], dp[505];

	for(int i = 0;i < p;i++){
		for(int j = 0;j < q;j++) cin >> arr[j];	
		if(i == 0) for(int j = 0;j < q;j++) dp[j] = (j==0)? arr[j]: dp[j-1] + arr[j];
		else for(int j = 0;j < q;j++) dp[j] = (j==0)? arr[j]+dp[j]: arr[j]+min(dp[j], dp[j-1]);
	}
	cout << dp[q-1];
}