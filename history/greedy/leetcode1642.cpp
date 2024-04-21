#include <bits/stdc++.h>
#define ilovekanade ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    const int n = heights.size();
    priority_queue <int> q;
    int i = 0;
    for(;i < n-1;i++){
        if(heights[i] < heights[i+1]){
            bricks -= heights[i+1]-heights[i];
            q.push(heights[i+1]-heights[i]);
            if (bricks < 0){
                if(ladders){
                    bricks += q.top();
                    q.pop();
                    ladders--;
                }else return i;
            }
        }
    }
    return n-1;
}

int main(){
    int n, b, l; cin >> n >> b >> l; vector<int> h(n);for(int i = 0;i < n;i++) cin >> h[i];

    cout << furthestBuilding(h, b, l);
}