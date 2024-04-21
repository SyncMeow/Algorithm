#include <bits/stdc++.h>
using namespace std;

struct Node{
	int ans, one, zero;
};

Node find_pair(vector<int> &a, int l, int r){
	if (r==l) return {0, (a[l]==1), (a[l]==0)};
	
	int mid = l + (r-l)/2;
	Node ndl = find_pair(a, l, mid);
	Node ndr = find_pair(a, mid+1, r);
	return {ndl.ans + ndr.ans + ndl.zero*ndr.one, ndl.one+ndr.one, ndl.zero+ndr.zero};
}

int main(){
	int n; cin>> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++) cin >> a[i];
	
	Node nd = find_pair(a, 0, n);
	cout << nd.ans;
}
