#include <bits/stdc++.h>
#define fastio ios::sync_with_studio(0);cin.tie(0);
#define pii = pair<long long, int>
using namespace std;

const long long INF = 1e18;
const int MAXN = 1e5 + 5;

int n, m;
vector<pair<long long, int>> G[MAXN];
long long dis[MAXN];
bool vis[MAXN];

int find_target(){
    long long minV = INF;
    int idx = -1;
    for (int i = 0;i < n;i++){
        if (vis[i]) continue;
        if (dis[i] < minV){
            minV = dis[i];
            idx = i;
        }
    }
    return idx;
}

void Dijkstra(int source){
    fill(dis, dis + n, INF);
    fill(vis, vis + n, false);
    dis[source] = 0;
    for (int i = 0;i < n;i++){
        int u = find_target();
        vis[u] = true;
        for (int j = 0;j < (int)G[u].size();j++){
            long long weight = G[u][j].first;
            int endpoint = G[u][j].second;
            if (vis[endpoint]) continue;
            dis[endpoint] = min(dis[endpoint], dis[u] + weight);
        }
    }
}

void init(){
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int u, v; long long w;
        cin >> u >> v >> w;
        G[u].push_back({w, v});
    }
}

int main(){
    init();
    Dijkstra(0);
    for (int i = 0;i < n;i++){
        cout << i << ' ' << dis[i] << '\n';
    }
}