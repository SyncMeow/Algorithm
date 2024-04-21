#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	stack<pii> stk;
	vector<int> ans(n+5);
	for(int i = 0,t;i<n;i++){
		cin >> t;
		if (stk.empty()) ans[i] = 0;
		else if (t > stk.top().first) ans[i] = stk.top().second + 1;
		else{
			while(true){
				stk.pop();
				if (stk.empty()){
					ans[i] = 0;
					stk.push({t, i});
					break;
				}
				if (stk.top().first < t){
					ans[i] = stk.top().second + 1;
					stk.push({t, i});
					break;
				}
			}
		}
		stk.push({t, i});
	}
	for (int i = 0;i<n;i++)cout << ans[i] << " ";
}