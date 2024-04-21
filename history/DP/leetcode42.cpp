#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);

	int n; cin >> n;
	vector<int> h(n), l(n), r(n);
	for(int i = 0;i < n;i++){
		cin >> h[i];
		if (i==0) l[i] = h[i];
		else l[i] = max(h[i], l[i-1]);
	}
	for(int i = n-1;i >= 0;i--){
		if (i == n-1)r[i] = h[i];
		else r[i] = max(h[i], r[i+1]);
	}

	int ans = 0;
	for(int i = 0;i < n;i++) ans += min(l[i], r[i]) - h[i];
	
	cout << ans << "\n";
}