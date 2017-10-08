#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
string str[1000000];

int main()
{
  int n, m, r;
  scanf("%d %d", &n, &m);

  for(int i = 0; i < n + m; i++){
    cin >> str[i];
  }
  sort(str, str + n + m);

  vector<string> v;
  for(int i = 1; i < n + m; i++){
    if(str[i-1] == str[i]){
      v.push_back(str[i]);
    }
  }

  cout << v.size() << endl;
  for(int i=0; i<v.size(); i++){
    cout << v[i] << endl;
  }

  return 0;
}
