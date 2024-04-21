#include <iostream>
#include <algorithm>
using namespace std;

struct point {
	int x, y;
}P[1005];

bool cmp(point a, point b) {
	if (a.x == b.x)return a.y < b.y;
	return a.x < b.x;
}

int main() {
	int n; cin >> n;
	for (int i = 0, a, b; i < n; i++) {
		cin >> a >> b;
		P[i] = { a,b };
	}
	sort(P,P+n,cmp);
	for (int i = 0; i < n; i++)cout << P[i].x << " " << P[i].y<<"\n";
}