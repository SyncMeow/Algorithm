#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){return a.first > b.first;}

int main(){ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> a(n+5);
	vector<long long> prefix(n+5);
	
	for(int i = 1, t;i <= n;i++){
		cin >> t;
		a[i] = {t, i};
		prefix[i] = prefix[i-1] + t;
	}
	
	sort(a.begin(), a.end(), cmp);
	
	int l = 1, r = n;
	while(l < r){
		while(a.back().second < l || a.back().second > r) a.pop_back();
		int m = a.back().second; a.pop_back();
		
		if (prefix[m-1] - prefix[l-1] > prefix[r] - prefix[m]) r = m-1;
		else l = m+1;
	}
	
	cout << prefix[l] - prefix[l-1];
}
