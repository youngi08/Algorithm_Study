/*
  시험감독
  https://www.acmicpc.net/problem/13458
*/

#include <iostream>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int* classes = new int[N];
  int B, C;

  for(int i=0; i<N; i++){
    cin >> classes[i];
  }

  cin >> B >> C;

  long long res = 0;
  for(int j=0; j<N; j++){
    int tmp = (classes[j]-B)/C;
    int rtmp = (classes[j]-B)%C;

    if(classes[j] <= B) continue;

    if(rtmp == 0) res += tmp;
    else res += tmp+1;
  }

  cout << N+res << endl;

  delete[] classes;

  return 0;
}
