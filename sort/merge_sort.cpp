#include <bits/stdc++.h>
using namespace std;

const int Max = 1<<30;

void Merge(vector<int> &Array, int front, int mid, int end){
	vector<int> LeftSub(Array.begin()+front, Array.begin()+mid+1);
	vector<int> RightSub(Array.begin()+mid+1, Array.begin()+end+1);

	LeftSub.insert(LeftSub.end(), Max);
	RightSub.insert(RightSub.end(), Max); 

	int l = 0, r = 0;
	for (int i = front; i <= end; i++) {
		if (LeftSub[l] <= RightSub[r] ) {
			Array[i] = LeftSub[l];
			l++;
		}
		else{
			Array[i] = RightSub[r];
			r++;
		}
	}
}

void MergeSort(vector<int> &array, int front, int end){
	if (front < end) {
		int mid = (front+end)/2;
		MergeSort(array, front, mid);
		MergeSort(array, mid+1, end);
		Merge(array, front, mid, end);
	}
}

int main() {
	int n; cin >> n;
	vector<int> array(n);
	for(int i = 0; i<n; i++)cin >> array[i];

	MergeSort(array, 0, array.size() - 1);
	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}

	return 0;
}