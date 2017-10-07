// https://www.acmicpc.net/problem/14503
#include <iostream>
using namespace std;

#define BLANK 0
#define WALL 1
#define CLEAN 2

int map[51][51] = {0};
//void dfs(int x, int y, int dir, int (*arr[])[M])
void dfs(int x, int y, int dir)
{
  int cnt = 0;

  while(1){
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    // 1.현재 위치 청소
    if(map[x][y] == BLANK){
      cnt++;
      map[x][y] = CLEAN;
    }

    bool ret = false;

    // 2.현재 방향에서 왼쪽 방향으로 탐색을 진행
    for(int i=0; i<4; i++){
      int nd = (dir - 1 + 4) % 4; // 어떻게 이렇게 공식으로 할 수 있지?
      int nx = x + dx[nd];
      int ny = y + dy[nd];

      // 2-1.왼쪽방향에 아직 청소하지 않은 공간이 존재하면, 그 방향으로 회전한다음 한 칸을 전진하고 청소
      if(map[nx][ny] == BLANK){
        dir = nd;
        x = nx;
        y = ny;

        ret = true;
        break;
      }
      // 2-2.그 방향에 청소할 방향이 없다면, 그 방향으로 그냥 회전한다
      else{
        dir = nd;
      }
    }

    if(!ret) {
      // 2-4. 4방향 청소할 곳이 없고, 후진도 불가능한 경우 종료
      if(map[x - dx[dir]][y - dy[dir]] == WALL){
        cout << cnt << endl;
        break;
      }
      // 2-3. 4방향 청소할 곳이 없고 후진이 가능한 경우에 그냥 후진
      else {
        x -= dx[dir];
        y -= dy[dir];
      }
    }
  }
}

int main()
{
  int N, M;
  int r, c, d; // (r,c) 청소기 위치

  cin >> N >> M;
  cin >> r >> c >> d;
/*
  int **map = new int*[N];
  for(int i = 0; i < N; ++i){
    map[i] = new int[M];
    memset(map[i], 0, sizeof(int)*M);
  }
*/
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> map[i][j];
    }
  }
  //dfs(r, c, d, map);
  dfs(r, c, d);

  return 0;
}
