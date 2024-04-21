#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string ans = "";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int dl[15];
		string rule = "";
		for (int j = 0; j < 14; j++) {
			cin >> dl[j];
		}
		if (dl[1] == dl[3] || dl[1] != dl[5] || dl[8] == dl[10] || dl[8] != dl[12]) {
			rule += "A";
		}
		if (dl[6] == 0 || dl[13] == 1) {
			rule += "B";
		}
		if (dl[1] == dl[8] || dl[3] == dl[10] || dl[5] == dl[12]) {
			rule += "C";
		}
		if (rule == "") {
			ans += "None";
		}
		else {
			for (char c : rule) {
				ans += c;
			}
		}
		ans += "\n";
	}
	for (char c : ans) {
		cout << c;
	}

}