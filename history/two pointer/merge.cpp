#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a, b;

void init(){
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for(int i = 0;i <n;i++)cin>>a[i];
	for(int i = 0;i <m;i++)cin>>b[i];
	a.push_back(1e9);
	b.push_back(1e9);
}

int main(){
	init();
	vector<int> c;
	int first = 0, second = 0;
	while(first < n || second < m){
		if(a[first] > b[second]){
			c.push_back(b[second]);
			second++;
		} 
		else {
			c.push_back(a[first]);
			first++;
		}
	}
	for (int i = 0; i< n+m;i++){
		cout << c[i] << " ";
	}
}
