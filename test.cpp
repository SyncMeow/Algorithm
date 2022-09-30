#include <bits/stdc++.h>
#include <vector>
using namespace std;

int binary_search(vector<int> &arr, int target){
	sort(arr.begin(), arr.end());
	int l = 0, r = arr.size() - 1;
	while(l<=r){
		int m = r + (l-r)/2;
		if (target == arr[m]){
			return m;
		}else if (target < arr[m]){
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	return -1;
}

int main(){
	int N;cin>> N;
	vector<int> a(N);
	for(int i = 0;i<N;i++)cin >> a[i];

	int target;cin>>target;
	cout << binary_search(a, target);
}
