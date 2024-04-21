#include <iostream>
using namespace std;

int main() {
	int c[12] = {0}; int cnt = -1;
	for (int i = 0; i < 3; i++) {
		int x; cin >> x;
		c[x]++;
		if (c[x] > cnt)cnt = c[x];
	}
	cout << cnt << " ";
	for(int i = 9;i>0;i--){
		if (c[i] != 0) {
			cout << i << " ";
		}
	}
}