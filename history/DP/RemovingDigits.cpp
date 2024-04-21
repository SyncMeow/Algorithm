#include <bits/stdc++.h>
using namespace std;

int dp[1000005];

int main(){
    int n; cin >> n;
    
    memset(dp, 0x3f, sizeof(dp));//神奇的東西
    dp[0] = 0;
    for(int i = 1;i <= n;i++){//計算dp[1~n]
        int tmp = i;
        while(tmp){//對於每個i計算當下最小次數(以i的每個位數進行運算)
            dp[i] = min(dp[i], dp[i-tmp%10]+1);
            tmp/=10;
        }
    }
    cout << dp[n] << '\n'; 
}
