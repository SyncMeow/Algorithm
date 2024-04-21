#include <bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int left, int right){
	int temp;
	if (left < right){
		int pivot = arr[left];
		int l = left;
		int r = right + 1;
		
		while (1){
			while (l < right && arr[++l] < pivot);
			while (r > 0 && arr[--r] > pivot);
	
			if (l >= r){
				break;
			}
		
			swap(arr[l], arr[r]);
		}
	
		swap(arr[left], arr[r]);
	
		quickSort(arr, left, r - 1);
		quickSort(arr, r + 1, right);
	}
}

int main(){
	int N;int a[35];
	cin>>N;
	for(int i = 0; i< N;i++)cin>>a[i];
	quickSort(a, 0, N - 1);
	for (int i = 0; i < N; i++)cout << a[i]<< " ";
}