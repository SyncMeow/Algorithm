#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int k; string s;
	cin >> k >> s;
	int a[100000];
	for (int i = 0; i < s.size();i++) {
		a[i] = ('A'<=s[i]&&s[i]<='Z');
	}
	vector <int> b;
	int cnt = 1;
	for (int i = 0; i < s.size()-1; i++) {
		if (a[i] == a[i + 1])cnt++;
		else {
			b.push_back(cnt);
			cnt = 1;
		}
	}
	b.push_back(cnt);

	vector <int> ans;
	cnt = 0;
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == k)cnt++;
		else {
			if ((i - cnt - 1) >= 0 && (b[i - cnt - 1] > k))cnt++;
			if (b[i]>k)cnt++;
			ans.push_back(cnt);
			cnt = 0;
		}
	}
	if (cnt > 0) {
		if (b[b.size() - cnt - 1] > k)cnt++;
		ans.push_back(cnt);
	}

	int mx = 0;
	for (auto i : ans) {
		if (i > mx) mx = i;
	}

	cout << mx * k << "\n";
}