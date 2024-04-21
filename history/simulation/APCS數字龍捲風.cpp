#include "pch.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;



int main() {
	int n, d; cin >> n >> d;
	int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
	int data[55][55] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> data[i][j];
		}
	}
	int x = n / 2; int y = n / 2;
	int num = 1; int step = 1; int dstep = 0;
	cout << data[x][y];
	while (num < n*n) {
		for (int i = 0; i < step; i++) {
			x += dir[d][0];
			y += dir[d][1];
			cout << data[x][y];
			num++;
			if (num == n * n) {
				break;
			}
		}
		d++;
		dstep++;
		if (dstep % 2 == 0) step++;
		d %= 4;
	}
}