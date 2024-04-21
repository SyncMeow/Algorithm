#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 50;

int seg[MAXSIZE<<2], a[MAXSIZE];

void build(int node, int l, int r){//O(N)
    if(l == r){
        seg[node] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(node*2+1, l, mid);
    build(node*2+2, mid+1, r);
    seg[node] = min(seg[node*2+1], seg[node*2+2]);
}

int query(int node, int l, int r, int Lb, int Rb){//O(logN)
    if (Lb <= l && r <= Rb)return seg[node];//當查詢區間完全位於[Lb, Rb]內回傳seg[node];
    
    int mid = (l+r)/2;
    if (Rb <= mid) return query(node*2+1, l, mid, Lb, Rb);//查詢區間整個位於mid左邊
    else if (mid < Lb) return query(node*2+2, mid+1, r, Lb, Rb);//查詢區間整個位於mid右邊
    else return min(query(node*2+1, l, mid, Lb, Rb), query(node*2+2, mid+1, r, Lb, Rb));
}

void update(int node, int l, int r, int pos, int val){//O(logN)
    if (l == r){
        seg[node] = val;
        return;
    }
    int mid = (l+r)/2;
    if (pos <= mid) update(node*2+1, l, mid, pos, val);
    else update(node*2+2, mid+1, r, pos, val);
    seg[node] = min(seg[node*2+1], seg[node*2+2]);
}

int main(){
    int n, t; cin >> n >> t;
    for(int i = 0, x;i < n;i++){
        cin >> x;
        update(0, 0, n-1, i, x);
    }
    while(t--){
        int x, y;cin >> x >> y;

        cout << query(0, 0, n-1, x, y)<<'\n';
    }
    
}