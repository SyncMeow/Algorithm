#include <iostream>
#include <string>

using namespace std;
string s;
int width;
int index = -1;

int f(int w) {
	index++;
	if (s[index] == '0')return 0;
	else if (s[index] == '1')return w * w;
	else {
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			sum += f(w/2);
		}
		return sum;
	}
}

int main() {
	cin >> s >> width;
	cout << f(width) << "\n";
}