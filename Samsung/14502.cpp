/*
  연구소
  https://www.acmicpc.net/problem/14502
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int map[8][8] = {0};
int tmp[8][8] = {0};
int m, n, max_value = 0;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

vector<pair<int, int>> virus;

bool chk(int x, int y)
{
  return(x>=0 && x<m && y>=0 && y<n);
}

void copy_map()
{
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      tmp[i][j] = map[i][j];
    }
  }
}

int recovery()
{
  int ret = 0;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(map[i][j] == 0) ret++;
      map[i][j] = tmp[i][j];
    }
  }
  return ret;
}

void bfs()
{
  queue<pair<int, int>> q;

  for(int i = 0; i < virus.size(); i++){
    q.push(virus[i]);
  }

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(chk(nx, ny) && map[nx][ny] == 0){
        map[nx][ny] = 2;
        q.push(make_pair(nx, ny));
      }
    }
  }
}

void dfs(int x, int y, int d)
{
  map[x][y] = 1;

  if(d == 3){
    copy_map();
    bfs();
    max_value = max(max_value, recovery());

    map[x][y] = 0;
    return;
  }

  for(int i = x; i < m; i++){
    for(int j = 0; j < n; j++){
      if(map[i][j] == 0) dfs(i, j, d + 1);
    }
  }

  map[x][y] = 0;
}


int main()
{
  cin >> m >> n;

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cin >> map[i][j];

      if(map[i][j] == 2) virus.push_back(make_pair(i, j));
    }
  }

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(map[i][j] == 0) dfs(i, j, 1);
    }
  }

  cout << max_value << endl;

  return 0;
}
