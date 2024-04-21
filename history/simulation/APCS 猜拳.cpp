#include <iostream>
using namespace std;

struct fist{
	int win, lost, drew;
}a[6];

int main() {
	int f, n, y[20];
	a[0] = {5,2,0};
	a[2] = {0,5,2};
	a[5] = {2,0,5};
	cin >> f >> n;
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	for (int i = 0; i < n; i++) {
		if (f == a[y[i]].drew) {
			cout << f << " ";
			if (i>0 && y[i] == y[i-1]) {
				f = a[y[i]].win;
			}
			else {
				f = y[i];
			}
		}
		else {
			if (f == a[y[i]].win) {
				cout << f << " : Won at round " << i + 1 << "\n";
			}
			else{
				cout << f << " : Lost at round " << i + 1 << "\n";
			}
			return 0;
		}
	}
	cout << ": Drew at round " << n<<"\n";
	return 0;

}