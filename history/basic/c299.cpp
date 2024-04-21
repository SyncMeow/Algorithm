#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>> n;
	vector<int> arr(n);
	for(int i = 0; i<n ;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());

	int MIN = arr[0], MAX = arr[n-1];

	for(int i = 0;i<=n-2;i++){
		if(arr[i+1] - arr[i] != 1){
			cout << MIN <<" " << MAX << " no\n";
			return 0;
		}
	}
	cout << MIN << " " << MAX << " yes\n";
}
