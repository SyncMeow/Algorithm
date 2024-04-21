#include <iostream>
using namespace std;

int max(int a,int b){
  if (a>b){
    return a;
  }else{
    return b;
  }
}

int main(){
  int dp[51][10000] = {0},a[10000],l[10000],r[10000];
  int m,n;
  cin >> m >> n;
  for (int i =1;i <= m;i++){
    for (int j = 1;j<=n;j++){
      cin >> a[j];
    }
    for (int j =1;j<=n;j++){//算出由左過來的最大值
      if (j==1){
        l[j] = dp[i-1][j] + a[j];
      }else{
        l[j] = max(dp[i-1][j],l[j-1]) + a[j];
      } 
    }
    for (int j = n; j >= 1;j--){//算出由右過來的最大值
      if (j == n){
        r[j] = dp[i-1][j] + a[j];
      }else{
        r[j] = max(dp[i-1][j],r[j+1]) + a[j];
      }
    }
    for (int j = 1;j<=n;j++){//比較由右最大來還是左
      dp[i][j] = max(l[j],r[j]);
    }
  }

  int mx = -1e9;
  for (int j = 1;j<=n;j++){
    mx = max(mx,dp[m][j]);
  }

  cout << mx;
}