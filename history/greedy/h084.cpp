#include <bits/stdc++.h>
#define abb ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n, k;
vector<int> height, post;

bool canplace(int h){
    int count = 0, pointer = -1;
    for(int i = 0;i < n+1;i++){
        if (height[i] < h) pointer= i;
        else if (i - pointer == post[count]){
            pointer = i;
            count++;
            if (count == k)break;//防止因為海報已經貼完了而去取用超過post範圍的數字
        }
    }
    return count == k;
}

int main(){
    abb
    cin >> n >> k;
    for(int i = 0, t;i < n;i++){
        cin >> t;
        height.push_back(t);
    }
    height.push_back(-1);
    for(int i = 0, t;i < k;i++){
        cin >> t;
        post.push_back(t);
    }
    
    int l = 1, r = 1e9;
    while(l != r){//往上找答案
        int mid = l + (r-l+1)/2;
        if (canplace(mid))l = mid;
        else r = mid-1;
    }

    cout << l << '\n';
}