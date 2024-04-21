#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m,num[105][105],S=0,max=0;
	vector <int> t,t1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num[i][j];
			if (max < num[i][j]) {
				max = num[i][j];
			}
		}
		t.push_back(max);
		max = 0;
	}
	for (int i : t) {
		S += i;
	}
	for (int i : t) {
		if (S%i == 0) {
			t1.push_back(i);
		}
	}
	cout << S << "\n";
	if ((int)t1.size() == 0) {
		cout << -1<<"\n";
	}
	else {
		for (int i : t1) {
			cout << i << " ";
		}
		cout << endl;
	}
}