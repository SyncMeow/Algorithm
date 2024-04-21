#include <bits/stdc++.h>
#define abb ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int MAX = 1e9;

bool logic(int x){
    return true;
}

//往上找答案
void b1(){ //( !=, l+r+1, mid, mid-1, l)
    int l = 0, r = MAX;
    while(l != r){
        int mid = l + (r-l+1)/2;
        if (logic(mid))l = mid;
        else r = mid-1;
    }
    cout << l << '\n';
}

//往下找答案
void b2(){ //( <, l+r, mid, mid+1, r)
    int l = 0, r = MAX;
    while(l < r){
        int mid = l + (r-l)/2;
        if (logic(mid))r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
}

//普通二分搜
int b3(vector<int> &arr, int target){//( <=, l+r, mid-1, mid-1, mid)
    int l = 0, r = arr.size()-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) r = mid-1;
        else l = mid+1;
    }
    return -1;
}

int main(){
    abb
    int n, t; cin >> n >> t;
    vector<int> arr(n);
    for(int i = 0;i < n;i++) cin >> arr[i];
}