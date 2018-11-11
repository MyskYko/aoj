#include <iostream>
#include <string>
using namespace std;

int main()
{
  int c,t;
  string str,tmp,W;
  while(c = cin.get(), c != '\n') {
    if(c >= 'A' && c <= 'Z') W.push_back(c-'A'+'a');
    else if(c >= 'a' && c <= 'z') W.push_back(c);
  }
  t = 0;
  while(cin >> tmp, tmp != "END_OF_TEXT") {
    for(int i = 0; i < (int)tmp.size(); i++){
      c = tmp[i];
      if(c >= 'A' && c <= 'Z') str.push_back(c-'A'+'a');
      else if(c >= 'a' && c <= 'z') str.push_back(c);
    }
    if(str == W) t++;
    str.clear();
  }
  cout << t << endl;
}

