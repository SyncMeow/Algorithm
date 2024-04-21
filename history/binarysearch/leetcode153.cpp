#include <bits/stdc++.h>
#define ilovekanade ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int findMin(vector<int>& nums) {
    int l = 0, r = nums.size()-1;
    while(l < r){
        int mid = l + (r-l)/2;
        if(nums[l] <= nums[mid] && nums[mid] <= nums[r]) break;
        else if (nums[mid] < nums[r]) r = mid;
        else l = mid + 1;
    }
    return nums[l];
}

int main(){
    ilovekanade
    vector<int> a = {2,2,2,0,1};
    cout << findMin(a);
}