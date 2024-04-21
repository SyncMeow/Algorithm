#include <bits/stdc++.h>
#define cock ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> arr(n+1);
    for(int i = 1;i <= n;i++) cin >> arr[i];

    stack<pair<int, int>> stk;
    for(int i = 1;i <= n;i++){
        if (stk.empty()){
            cout << "0 ";
            stk.push({i, arr[i]});
        }else{
            if (stk.top().second < arr[i]){
                cout << stk.top().first << ' ';
                stk.push({i, arr[i]});
            }else{
                while(1){
                    if (stk.empty()){
                        stk.push({i, arr[i]});
                        cout << "0 ";
                        break;
                    }
                    if (stk.top().second < arr[i]){
                        cout << stk.top().first <<' ';
                        stk.push({i, arr[i]});
                        break;
                    }else stk.pop();
                }
            }
        }
    }
}
