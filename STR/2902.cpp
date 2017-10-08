/*
  KMP는 왜 KMP일까?
  https://www.acmicpc.net/problem/2902
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
  string str;
  cin >> str;

  vector<char> v;
  v.push_back(str[0]);

  for(int i=0; i<str.size(); i++){
    if(str[i] == '-'){
      v.push_back(str[i+1]);
    }
  }

  for(int i=0; i<v.size(); i++){
    cout<<v[i];
  }

  return 0;
}
