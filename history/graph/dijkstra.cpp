#include <bits/stdc++.h>
#define abb ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
using namespace std;

const long long MAX = 1e5+5, INF = 1e18; 
vector<pair<int, int>> G[MAX];
long long dis[MAX];
bool vis[MAX];
int n, m;

int find_target(){
    long long MinV = INF;
    int idx = -1;
    for(int i = 0;i < n;i++){
        if (vis[i]) continue;
        if (dis[i] < MinV){
            MinV = dis[i];
            idx = i;
        }
    }
    return idx;
}

long long dijkstra(int source, int destination){//O(V^2 + E) 
    fill(dis, dis+n+1, INF);
    fill(vis, vis+n+1, false);
    dis[source] = 0;
    for(int i = 0;i < n;i++){
        int u = find_target(); 
        vis[u] = true;
        for(int j = 0;j < (int)G[u].size();j++){
            int v = G[u][j].second;
            long long w = G[u][j].first;
            if (vis[v]) continue;
            dis[v] = min(dis[v], dis[u] + w);
        }
    }
    return dis[destination];
}

long long Dijkstra(int source, int destination){//O(V + ElogV)
    fill(dis, dis+n+1, INF);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while(pq.size()){
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dis[u] != INF) continue;//visited
        dis[u] = d;

        for(int i = 0;i < (int)G[u].size();i++){
            long long w = G[u][i].first;
            int v = G[u][i].second;
            pq.push({d + w, v}); 
        }
    }
    return dis[destination];
}

int main(){
    int t;
    cin >> n >> m >> t;
    for(int i = 0;i < m;i++){
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({w, v});
    }

    while(t--){
        int sor, des; cin >> sor >> des;
        cout << Dijkstra(sor, des) << '\n';
    }

}