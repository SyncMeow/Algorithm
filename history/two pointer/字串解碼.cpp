#include <iostream>
#include <string>
using namespace std;

string trans(string &T, string &e) {
	int n = T.size(), l = 0, r = n - 1, sum = 0;
	string S;
	for (int i = 0; i < n; i++)S += ' ';
	for (int i = 0; i < n; i++) {
		if (e[i] == '0')S[l++] = T[i];
		else S[r--] = T[i];
	}
	for (char c : e)sum += c;// ASCII code: 1 => 49, 0 => 48
	for (int i = 0; i < n >> 1; i++) {
		if (sum & 1) swap(S[i],S[i + (n>>1) + (n&1)]);// &1 detect if it is even // >>1 make it /2
	}
	return S;
}

int main() {
	int n, m; string E[105], s;
	cin >> m >> n;
	for (int i = 1; i <= m; i++)cin >> E[i];
	cin >> s;
	for (int i = m; i; i--)s = trans(s, E[i]);
	cout << s << "\n";
}