/*
  막대기
  https://www.acmicpc.net/problem/1094
*/

#include <iostream>
using namespace std;

int main()
{
  int stick = 64;
  int X;
  cin >> X;

  int res = 0;
  while(1){
    if(X == 0 || X == stick){
      res++;sda;a;lskdl;aksl;dk;l
      break;
    }

    if(X < stick) stick /= 2;
    else{
      X -= stick;
      res++;
    }
  }
  cout << res << endl;

  return 0;
}
