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

	int l = 0, r = n-1;
	while(l<r){
		int sum = arr[l].first + arr[r].first;
		if(sum > x){
			r--;
		}else if (sum < x){
			l++;
		}else{
			cout << arr[l].second << " " << arr[r].second <<"\n";
			return 0;
		}
	}

	cout << "IMPOSSIBLE\n";
}
