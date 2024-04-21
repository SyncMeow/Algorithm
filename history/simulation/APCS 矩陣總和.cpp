#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int s, t, n, m, r;
	cin >> s >> t >> n >> m >> r;
	vector <int> dev;
	int a[105][105],b[105][105];
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < t; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}

	//scan
	for (int i = 0; i < n - s + 1; i++) {
		for (int j = 0; j < m - t + 1; j++) {
			//start point b[i][j]
			//scan range b[i][j] ~ b[s+i-1][t+j-1]
			int dis = 0,suma = 0,sumb = 0;
			for (int k = i; k <= s + i - 1; k++) {
				for (int h = j; h <= t + j - 1; h++) {
					//range a[0][0] ~ a[s-1][t-1]
					if (b[k][h] != a[k-i][h-j]) {
						dis++;
					}
					suma += a[k - i][h - j];
					sumb += b[k][h];
				}
			}
			if (dis <= r) {
				dev.push_back(abs(suma - sumb));
			}
		}
	}

	if (dev.size() > 0) {
		int min = 10000,c = 0;
		for (int i : dev) {
			c++;
			if (i < min)min = i;
		}
		cout << c << "\n" << min << "\n";
	}else{
		cout <<0<<"\n"<< -1 <<"\n";
	}
}