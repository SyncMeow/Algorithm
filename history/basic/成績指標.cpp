#include <iostream>
using namespace std;

int main() {
	int n,sco[25];
	bool AP = 1, AF = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sco[i];
	}

	int tmp;
	for (int i = 0; i < n;i++) {
		if (sco[i]>=60) {
			AF = 0;
		}
		else {
			AP = 0;
		}
	}

	
	while (1) {
		bool k = 0;
		for (int i = 0; i < n - 1; i++) {
			if (sco[i] > sco[i + 1]) {
				tmp = sco[i];
				sco[i] = sco[i + 1];
				sco[i + 1] = tmp;
				k = 1;
			}
		}
		if (!k) {
			break;
		}
	}

	int hf = 0, lp = 100;
	for (int i = 0,v; i < n;i++) {
		v = sco[i];
		cout << v;
		if (v<60 && v>hf){
			hf = v;
		}
		if (v >= 60 && v < lp) {
			lp = v;
		}
		if (i != (n-1)) {
			cout << " ";
		}
		v = 0;
	}
	cout << "\n";

	if (AP) {
		cout << "best case\n" << lp;
	}
	else if (AF) {
		cout << hf<<"\n" << "worst case";
	}
	else {
		cout << hf << "\n" << lp << "\n";
	}
	
}