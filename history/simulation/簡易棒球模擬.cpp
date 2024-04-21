#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

int main() {
	int a, target;
	string s;
	map<int, queue<string>> mp;

	for (int i = 0; i < 9; i++) {
		cin >> a;
		queue<string> q;
		for (int j = 0; j < a;j++) {
			cin >> s;
			q.push(s);
		}
		mp[i] = q;
	}
	cin >> target;

	int out = 0, num = -1, score = 0;
	int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
	while (1) {
		int times = 0;
		num = (num + 1) % 9;
		string hit = mp[num].front();
		mp[num].pop();
		if (hit == "FO" || hit == "GO" || hit == "SO") {
			out++;
			if (out == target)break;
			if (out % 3 == 0)b1 = b2 = b3 = b4 = 0;
		}
		else if (hit == "HR") {
			times = 4;
		}
		else {
			times = hit[0] - '0';
		}
		
		for (int i = 0; i < times; i++) {
			b4 = b3;
			b3 = b2;
			b2 = b1;
			if (i == 0)b1 = 1;
			else b1 = 0;
			if (b4 == 1)score++;
		}
	}
	cout << score << "\n";
}