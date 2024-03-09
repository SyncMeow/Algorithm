#include <bits/stdc++.h>
using namespace std;

int maxn = 100000;

vector<bool> p(maxn, true);

void sieve(){
    p[0] = p[1] = false;

    for (int i = 2; i*i < maxn; i++){
        if (!p[i]) continue;
        for (int j = i*i; j < maxn; j += i){
            p[j] = false;
        }
    }
}

int main(){
    sieve();
    for (int i = 2;i < maxn;i++){
        if (p[i]) cout << i << " ";
    }
}