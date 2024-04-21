#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums){
	int n = nums.size();
	if(n==0)return 0;
	if(n==1)return nums[0];
	int a = nums[0], b = max(nums[0], nums[1]);
	for(int i = 2;i < n;){
		a = (i<n)? max(b, a+ nums[i++]): a;
		b = (i<n)? max(a, b+ nums[i++]): b;
	}
	return max(a, b);
}

int main(){
	int n; cin >> n;
	vector<int> v(n);for(int i = 0;i < n;i++) cin >> v[i];
	cout << rob(v);
}