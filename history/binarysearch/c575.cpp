#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> p;

void init(){
	cin >> n >> k;
	p.resize(n);
	for(int i = 0;i < n;i++)cin >> p[i];
	sort(p.begin(), p.end());
}

bool check(int d){
	int cnt = 1;
	int last = p[0];
	for(int i = 1;i < n;i++){
		if(p[i] > last + d){
			last = p[i];
			cnt++;
		}
	}
	return cnt <= k;
}

void solve(){
	int l = 1, r = 1e9;
	while(l < r){
		int mid = l + (r-l)/2;
		if (check(mid)){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	cout << r << "\n";
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	init();
	solve();
}
