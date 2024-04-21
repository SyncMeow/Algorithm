#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int a = 1, b, c = 0;
	while(n--){
		cin >> b;
		a = max(a, b);
		c = max(c, a - b);
	}
	cout << c;
}