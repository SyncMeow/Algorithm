//binary search + bfs
#include <bits/stdc++.h>
#include <queue>
using namespace std;

int n;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int arr[305][305], bfs[310][310];

int BFS(int maxdh){
	int x, y;
	queue<pair<int,int>> search;

	search.push({1, 1});
	while(!search.empty()){
		x = search.front().first; y = search.front().second;
		search.pop();
		for(int i = 0;i < 4;i++){
			if (bfs[x + dx[i]][y + dy[i]] == 0 && abs(arr[x][y] - arr[x + dx[i]][y + dy[i]]) <= maxdh){
				search.push({x + dx[i], y + dy[i]});
				bfs[x+dx[i]][y+dy[i]] = bfs[x][y] + 1;
			}
		}
	}

	if (bfs[n][n] != 0) return bfs[n][n] - 1;
	else return -3;
}

void reset(){ 
	memset(bfs, -1, sizeof(bfs));
	for(int i = 1;i <= n;i++)for(int j = 1;j <= n;j++) bfs[i][j] = 0;
	bfs[1][1] = 1;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i ++) for(int j = 1;j <= n;j++) cin >> arr[i][j];

	int l = 1, r = 1000000;
	pair<int, int> ans;
	while(l < r){
		reset();
		int mid = l + (r - l)/2;
		int length = BFS(mid);
		if (length != -3){
			ans = {mid, length};
			r = mid;
		}else l = mid+1;
	}

	cout << ans.first << "\n" << ans.second;
}
