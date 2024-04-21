#include <bits/stdc++.h>
using namespace std;

struct point{int i, j, val;};

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    vector<point> a(m*n);

    int p = 0;
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) a[p++] = {i, j, matrix[i][j]};

    int l = 0, r = m*n-1, flag = 0;
    while(l<=r){
        int mid = l + (r-l)/2;
        if (a[mid].val < target)l = mid +1;
        else if(a[mid].val > target)r = mid-1;
        else{
            flag = 1;
            break;
        }
    }
    return flag;
}

int main(){
    int m, n, t; cin >> m >> n >> t;
    vector<vector<int>> v(m, vector<int>(n));
    for(int i = 0;i < m;i++)for(int j = 0;j < n;j++)cin >> v[i][j];

    cout << searchMatrix(v, t);
}