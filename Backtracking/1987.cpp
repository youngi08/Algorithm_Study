/*
  알파벳
  https://www.acmicpc.net/problem/1987
*/
#include <iostream>
using namespace std;

char map[21][21] = {0};
bool alpha[27] = {0};
int N, M;
int res = 0;

bool chk(int x, int y)
{
  return(x>=0 && x<N && y>=0 && y<M);
}

void dfs(int x, int y, int c)
{
  alpha[map[x][y] -'A'] = true;

  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};

  if(res < c) res = c;

  for(int i=0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(chk(nx, ny) && !alpha[map[nx][ny] - 'A']) dfs(nx, ny, c+1);
  }

  alpha[map[x][y] -'A'] = false;
}

int main()
{
  cin >> N >> M;

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> map[i][j];
    }
  }

  dfs(0,0,1);

  cout << res << endl;

  return 0;
}
