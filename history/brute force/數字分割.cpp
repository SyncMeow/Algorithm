#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int pair[1005][6];
	vector <int> s, s1;
	int v;
	cin >> v;
	int i = 0;
	for (int h1 = 1; h1 <= round(pow(v,0.5)); h1++) {
		if (v%h1 == 0) {
			for (int w1 = 1; w1 <= round(pow((v / h1),0.5)); w1++) {
				if ((v / h1) % w1 == 0) {
					i++;
					int l1 = (v / h1) / w1;
					pair[i][1] = l1;
					pair[i][2] = w1;
					pair[i][3] = h1;
					pair[i][4] = 2 * (l1*w1 + l1 * h1 + w1 * h1);
					
				}
			}
		}
	}

	long long int a = 10000000000;

	for (int k = 1; k <= i; k++) {
		if (pair[k][4] < a) {
			a = pair[k][4];
		}
	}
	for (int k = 1; k <= i; k++) {
		if (pair[k][4] == a) {
			s.push_back(k);
		}
	}

	for (int x = 3; x >= 1; x--) {
		a = 10000000000;
		for (int k : s) {
			if (pair[k][x] < a) {
				a = pair[k][x];
			}
		}
		for (int k : s) {
			if (pair[k][x] == a) {
				s1.push_back(k);
			}
		}
		s = s1;
		s1.clear();
	}

	cout << pair[s[0]][4] << " " << pair[s[0]][3] << " " << pair[s[0]][2] << " " << pair[s[0]][1] << " " << endl;
}