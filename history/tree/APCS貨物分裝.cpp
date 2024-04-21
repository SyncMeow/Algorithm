#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

struct node{
    int l = 0, r = 0, wl = 0, wr = 0, w = 0;//l, r are the index of the neighbors
    int type = 0; //0: seperator  1: box 
}a[200005];

int update(node &cur){
    if (cur.type == 1) return cur.w;
    cur.wl = update(a[cur.l]);
    cur.wr = update(a[cur.r]);
    return cur.wl + cur.wr;
}

int add(int weight, int idx, node &cur){
    if (cur.type == 1) {
        cur.w += weight;
        return idx;
    }
    if (cur.wl > cur.wr){
        cur.wr += weight;
        return add(weight, cur.r, a[cur.r]);
    }else{
        cur.wl += weight;
        return add(weight, cur.l, a[cur.l]);
    }
}

int main(){
    fastio
    int goods[105];
    int n, m; cin >> n >> m;
    for(int i = 0;i < n;i++){
        a[n+i].type = 1;
        cin >> a[n+i].w;
    }
    
    for(int i = 0;i < m;i++) cin >> goods[i];
    for(int i = 0;i < n-1;i++){
        int p, s, t; cin >> p >> s >> t;
        a[p].l = s;
        a[p].r = t;
    }
    
    int _ = update(a[1]);
    for(int i = 0;i < m;i++) {
        cout << add(goods[i], 1, a[1]) << ' ';
    }
}