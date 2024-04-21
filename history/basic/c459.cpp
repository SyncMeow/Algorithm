#include <bits/stdc++.h>
using namespace std;

int convert(int n, int c){
	int ans = 0, multi = 1;
	while(n){
		ans += n%10 * multi;
		multi*=c;
		n/=10;
	}
	return ans;
}

int main(){
	int c, N; cin >> c >> N;

	int cN = convert(N, c);

	vector<int> arr;
	while(N){
		arr.push_back(N%10);
		N/=10;
	}

	int sum = 0, power = arr.size();
	for(int i:arr){
		sum += (int)pow(i, power);
	}

	if(cN == sum)cout<< "YES\n";
	else cout << "NO\n";
}
