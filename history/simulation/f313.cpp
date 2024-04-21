#include <iostream>
using namespace std;

int f313(){
  int pos[1000][1000];
  int delta[1000][1000];
  int R,C,k,m;
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  cin >> R>>C>>k>>m;
  for (int i =0;i<R;i++){
    for(int j = 0;j<C;j++){
      cin >> pos[i][j];
    }
  }
  for (int x = 0;x<m;x++){
    for (int i = 0;i<R;i++){
      for(int j = 0;j<C;j++){
        if (pos[i][j] == -1){
          delta[i][j] = pos[i][j];
        }else{
          delta[i][j] = pos[i][j];
          for (int v = 0;v< 4;v++){
            int nx = i + dx[v];
            int ny = j + dy[v];
            if (nx >= 0 && nx< R && ny >= 0 && ny < C && pos[nx][ny] != -1){
              delta[i][j] += pos[nx][ny]/k;
              delta[i][j] -= pos[i][j]/k;
            }
            
          }

        }

      }

    }
    for (int i =0;i<R;i++){
      for(int j = 0;j<C;j++){
        pos[i][j] = delta[i][j];
      }
    }
  }




  int max = 0;
  int min = 1e9;

  for (int i =0;i<R;i++){
    for(int j = 0;j<C;j++){
      if (pos[i][j] != -1){
        if (pos[i][j] > max){
          max = pos[i][j];
        }
        if (pos[i][j]<min){
          min = pos[i][j];
        }
      }
    }
  }
  cout << min << endl;
  cout << max << endl;
}