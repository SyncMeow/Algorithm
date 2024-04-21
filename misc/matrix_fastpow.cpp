#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int, int>
using namespace std;
const int maxn = 1e6+10;
const int mod = 1e9+7;

struct matrix{
    long long mat[2][2];
    init(int val){
        mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = val;
    }

    print_out(){
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 2;j++){
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    val_set(int v00, int v01, int v10, int v11){
        mat[0][0] = v00;
        mat[0][1] = v01;
        mat[1][0] = v10;
        mat[1][1] = v11;
    }
};

matrix multipy(matrix a, matrix b){
    matrix c;
    c.init(0);
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            for(int k = 0;k < 2;k++){
                c.mat[i][j] += ((a.mat[i][k]%mod)*(b.mat[k][j]%mod))%mod;
                c.mat[i][j] %= mod;
            }
        }
    }
    return c;
}

matrix fastpow(matrix a, int n){
    matrix b = a;
    n--;
    while(n){
        if (n&1){
            b = multipy(b, a);
        }
        a = multipy(a, a);
        n>>=1;
    }
    return b;
}

int main(){
    int n; cin >> n;
    matrix a;
    a.val_set(1, 1, 1, 0);
    a = fastpow(a, n-1);
    cout << a.mat[0][0];
}