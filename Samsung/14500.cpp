/*
  테트로미노
  https://www.acmicpc.net/problem/14500
*/
#include <iostream>
#include <algorithm>

using namespace std;

int map[500][500] = {0};
int visit[500][500] = {0};

int N, M; //세로, 가로
int sum = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool chk(int x, int y)
{
  return(x>=0 && x< N && y>=0 && y< M);
}

int dfs(int x, int y, int c)
{
  if(c == 4) return map[x][y];

  visit[x][y] = true;

  int ret = map[x][y];
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(chk(nx, ny) && visit[nx][ny] == 0){
      ret = max(ret, map[x][y] + dfs(nx, ny, c+1));
    }
  }
    visit[x][y] = false;

    return ret;
}

int func(int x, int y) {
    int ret = 0, mmin = 987654321;
    int c[4] = { -1,-1,-1,-1 };
    for (int i = 0; i < 4; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (chk(cx, cy))
            c[i] = map[cx][cy];
    }
    int ct = 0;
    for (int i = 0; i < 4; i++)
        if (c[i] == -1)
            ct++;
    if (ct >= 2)return -1;
    for (int i = 0; i < 4; i++) {
        if (c[i] == -1)continue;
        ret += c[i];
        mmin = min(mmin, c[i]);
    }
    if (!ct)
        return ret - mmin + map[x][y];
    else
        return ret + map[x][y];
}

int main()
{
  cin >> N >> M;

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> map[i][j];
    }
  }

  int res = 0;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      res = max(res, dfs(i, j, 1));
      res = max(res, func(i, j));
    }
  }

  cout << res << endl;

  return 0;
}
