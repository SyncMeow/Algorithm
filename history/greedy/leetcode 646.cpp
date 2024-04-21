#include <bits/stdc++.h>
#define cock ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

bool cmp(vector<int> a, vector<int> b){return a[1] < b[1];}

int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), cmp);
    int pointer = pairs[0][1], cnt = 1;
    for(int i = 1;i < pairs.size();i++){
        if (pairs[i][0] > pointer){
            pointer = pairs[i][1];
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(5, 0));
    for(int i = 0;i < n;i++)cin >> arr[i][0] >> arr[i][1];

    cout << findLongestChain(arr);
}