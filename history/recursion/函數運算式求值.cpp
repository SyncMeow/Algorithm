#include <iostream>
#include <string>
using namespace std;

int f() {
	string s;
	cin >> s;
	if (s[0] == 'f') {
		int x = f();
		return 2 * x - 3;
	}
	else if (s[0] == 'g') {
		int x = f();
		int y = f();
		return 2 * x + y - 7;
	}
	else if (s[0] == 'h') {
		int x = f();
		int y = f();
		int z = f ();
		return 3 * x - 2* y + z;
	}
	else {
		return stoi(s);
	}
}

int main() {
	cout << f() << endl;
}