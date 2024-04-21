#include <bits/stdc++.h>
#define abb ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int, int>> v(n);

    for(int i = 0;i < n;i++){
        int start, end; cin >> start >> end;
        v.push_back({start, 1});
        v.push_back({end, -1});
    }

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){return a.first < b.first;});


    int total = 0, Max = -1; 
    for(pair<int, int> p: v){
        total += p.second;
        Max = max(Max, total);
    }

    cout << Max << '\n';
}