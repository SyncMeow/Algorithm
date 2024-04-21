#include <iostream>
#include <string>
#include <algorithm>
#define East 0
#define South 1
#define West 2
#define North 3
#define N 250005
using namespace std;

struct MIR {
	int x, y, idx;
}tmp[N];

int mir[N];
int next_d[2][4] = { {North,West,South,East},{South,East,North,West} };//type 0 = /, 1 = \ //
int adj[N][4];// -1 for none

bool cmpx(MIR a, MIR b) {
	if (a.x == b.x)return a.y < b.y;
	return a.x < b.x;
}
bool cmpy(MIR a, MIR b) {
	if (a.y == b.y)return a.x < b.x;
	return a.y < b.y;
}

int main() {
	int n; cin >> n;
	for (int i = 0, x, y; i < n; i++) {
		cin >> x >> y >> mir[i];
		tmp[i] = { x,y,i };
	}
	//find the neighbors
	for (int i = 0; i < n; i++)for (int j = 0; j < 4; j++)adj[i][j] = -1;
	sort(tmp, tmp + n, cmpx);
	for (int i = 0; i < n - 1; i++) {
		if (tmp[i].x == tmp[i + 1].x) {
			adj[tmp[i].idx][North] = tmp[i + 1].idx;
			adj[tmp[i + 1].idx][South] = tmp[i].idx;
		}
	}
	int v = -1;
	sort(tmp, tmp + n, cmpy);
	for (int i = 0; i < n - 1; i++) {
		if (tmp[i].y == tmp[i + 1].y) {
			adj[tmp[i].idx][East] = tmp[i + 1].idx;
			adj[tmp[i + 1].idx][West] = tmp[i].idx;
		}
		if (v == -1 && tmp[i].y == 0)v = tmp[i].idx;
	}

	//simulation
	int d = East, hit = 0;
	while (v >= 0) {
		hit++;
		d = next_d[mir[v]][d];
		v = adj[v][d];
	}
	cout << hit << "\n";
}