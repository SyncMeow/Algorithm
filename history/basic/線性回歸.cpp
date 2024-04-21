#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	double x[105], y[105],p,q,x2 = 0,sx = 0,xy = 0,n,sy = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		x2 += pow(x[i], 2);
		sx += x[i];
		xy += x[i] * y[i];
		sy += y[i];
	}
	p = (xy*n - sy * sx) / (x2*n - sx*sx)*1.0;
	q = ((-1)*sx*xy+sy*x2) / (sx*sx - x2*n)*1.0;
	int k = 0;
	if (abs(p) > abs(q)) {
		k = round(p);
	}
	else {
		k = round(q);
	}
	p = round(p * 100000) / 100000;
	q = round(q * 100000) / 100000;
	cout << setprecision(k + 5) << p <<" "<< q;
}