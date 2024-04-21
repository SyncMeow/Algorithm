#include <bits/stdc++.h>
using namespace std;

int main(){
	int p, q; cin >> p >> q;
	int arr[505], l[505], r[505], h[505], MIN = 1e9;

	for(int i = 0;i < p;i++){
		for(int j = 0;j < q;j++){
			cin >> arr[j];
			arr[j] += (i==0)? 0:h[j];
			l[j] = (j==0)? arr[j]: min(l[j-1]+arr[j], (i==0)?arr[j]:arr[j]+h[j]);
		}
		for(int j = q-1;j >= 0;j--)r[j] = (j==q-1)? arr[j]: min(r[j+1]+arr[j], (i==0)?arr[j]:arr[j]+h[j]);

		for(int j = 0;j < q;j++){
			h[j] = min(l[j], r[j]);
			if (i==p-1) MIN = min(MIN, h[j]);
		}
	}

	cout << MIN;
}
