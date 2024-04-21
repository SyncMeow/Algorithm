#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
    vector<long long> a(n), dp(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    dp[1] = abs(a[1]-a[0]);
    for(int i = 1;i < n;i++) dp[i] = min(dp[i-1]+abs(a[i]-a[i-1]), dp[i-2]+abs(a[i]-a[i-2]));
    cout << dp[n-1];
}
