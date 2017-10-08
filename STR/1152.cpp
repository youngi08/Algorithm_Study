/*
  단어의 개수
  https://www.acmicpc.net/problem/1152
*/

#include <iostream>
using namespace std;

int main()
{
  string str;
  getline(cin, str);

  int cnt = 0;
  for(int i=0; i<str.size(); i++){
    if(str[i] == ' ') cnt++;
  }

  /* 문장의 맨 앞,뒤 공백 주의*/
  if(str.at(0) == ' '){
    cnt--;
  }

  if(str.at(str.length()-1) == ' '){
    cnt--;
  }

  cout << cnt+1 << endl;

  return 0;
}
