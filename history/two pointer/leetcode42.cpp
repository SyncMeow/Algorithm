#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);

	int count = 0;

	int n; cin >> n;
	vector<int> h(n);
	for(int i = 0;i < n;i++) cin >> h[i];

	int l = 0, r = n-1, maxl = h[l], maxr = h[r], ans = 0;
	while(l<r){
		if (maxl<maxr){
			ans += maxl - h[l];
			maxl = max(maxl, h[++l]);
		}else{
			ans += maxr - h[r];
			maxr = max(maxr, h[--r]);
		}	
	}
	cout << ans << "\n";
	cout << count;
}