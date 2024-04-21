#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k; cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)cin >> arr[i];

	for(int i = 0; i < k; i++){
		int x; cin>> x;
		
		bool found = false;
		int l = 0, r = n-1;
		while(l<=r){
			int mid = l + (r-l)/2;
			if(arr[mid]>x){
				r = mid-1;
			}else if (arr[mid]<x){
				l = mid+1;
			}else{
				cout << mid+1 << "\n";
				found = true;
				break;
			}
		}

		if(!found)cout << "0\n";
	}

}