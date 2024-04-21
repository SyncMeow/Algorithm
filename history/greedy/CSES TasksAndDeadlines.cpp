#include <bits/stdc++.h>
#define cock ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main(){
    cock
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for(int i = 0;i < n;i++) cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b){return a.first < b.first;});

    long long current = 0, reward = 0;
    for(int i = 0;i < n;i++){
        current += arr[i].first;
        reward += arr[i].second - current;
    }
    cout << reward;
}
