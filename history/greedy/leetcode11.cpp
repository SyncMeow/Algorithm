#include <bits/stdc++.h>
#define ilovekanade ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int maxArea(vector<int>& height){
    const int n = height.size();
    int l = 0, r = n-1, ans = -1;
    while(l < r){
        ans = max(ans, min(height[l], height[r]) * (r-l));
        height[l] < height[r]? l++: r--;
    }
    return ans;
}

int main(){
    int n; cin >> n;
    vector<int> h(n); for(int i = 0;i < n;i++) cin >> h[i];
    cout << maxArea(h);
}