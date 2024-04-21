#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

bool cmp(pii a, pii b){
	return a.first < b.second;
}

int main(){
	int n, x;cin >> n >> x;
	vector<pii> arr(n);
	for(int i = 0, t; i<n; i++){
		cin >> t;
		arr[i] = {t, i+1};
	}
	sort(arr.begin(), arr.end(), cmp);

	for(int i = 0; i<n; i++){
		int l = 0, r = n-1;
		while(l!=r){
			int target = x - arr[i].first;
			if(r==i){
				r--;
				continue;
			}
			if(l==i){
				l++;
				continue;
			}
			if(arr[l].first + arr[r].first == target){
				cout << arr[i].second << " " << arr[l].second << " " << arr[r].second <<"\n";
				return 0;
			}
			if (arr[l].first + arr[r].first < x)l++;
			else r--;
		}
	}


	cout << "IMPOSSIBLE\n";
}
