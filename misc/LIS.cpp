#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n;
vector<int> arr;

void LIS(){
    vector<int> v;
    for(int i = 0;i < n;i++){
        int cur = arr[i];
        if (v.empty() || v.back() < cur) v.push_back(cur);
        else v[upper_bound(v.begin(), v.end(), cur)-v.begin()] = cur;
    }

    for(auto i: v) cout << i <<' ';
    cout << '\n' << v.size();
}

int main(){
    fastio
    cin >> n; arr.resize(n);
    for(int i = 0;i < n;i++) cin >> arr[i];
    LIS();
}