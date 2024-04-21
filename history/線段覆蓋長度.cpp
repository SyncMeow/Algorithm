#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;


bool f(pii a,pii b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N,a,b;
	cin >> N;
	
	vector <pii> v;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a,b });//get pairs 
	}
	sort(v.begin(),v.end(),f);//sort

	int s = 0, e = 0, ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].F>=e) {//not overlap
			ans += e - s;
			s = v[i].F;
			e = v[i].S;
		}
		else if (v[i].S>e) {
			e = v[i].S;
		}
	}
	ans += e - s;
	cout << ans<<"\n";
}