#include <bits/stdc++.h>
using namespace std;

int n, a[105];
int target;

int main(){
	cin >> n >> target;
	for(int i = 0;i<n;i++)cin>>a[i];
	int l = 0, r = 0, sum = 0, ans = 0;
	for(;l < n;l++){
		while(r < n && sum + a[r]< target){
			sum += a[r];
			r++;
		}
		ans = max(ans, r - l);
		sum -= a[l];
	}
	cout << ans;
}
