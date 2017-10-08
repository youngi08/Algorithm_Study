/*
  롤케이크
  https://www.acmicpc.net/problem/3985
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int L;
  cin >> L;
  int N;ㅁㅇㅁㄴㅇㄴㅁ
  cin >> N;

  int *cake = new int[L+1];
  for(int i=0; i<L+1; i++){
    cake[i] = 0;
  }

  int count = 0, expect = 0;
  int res = 0, real = 0;

  for(int i=0; i<N; i++){
    int P, K;
    cin >> P >> K;

    if(count < K-P+1){
      count = K-P+1;
      expect = i;
    }

    int gett = 0;
    for(int j=P; j<=K; j++){
      if(cake[j] == 0){
        cake[j] = 1;
        gett++;
      }
    }

    if(res < gett){
      res = gett;
      real = i;
    }
  }

  cout << expect+1 << endl;
  cout << real+1 << endl;

  return 0;
}
