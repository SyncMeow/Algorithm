#include <bits/stdc++.h>
#define ilovekanade ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int findMin(vector<int>& nums, int l, int r){
    if(l + 1 >= r) return min(nums[l], nums[r]);
    if(nums[l] < nums[r]) return nums[l];
    int mid = l + (r-l)/2;
    return min(findMin(nums, l, mid), findMin(nums, mid+1, r));
}

int main(){
    ilovekanade
    vector<int> a = {7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6};
    cout << findMin(a, 0, a.size()-1);
}