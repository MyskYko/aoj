#include <iostream>
#include <string>
using namespace std;


int main()
{
  int n, h;
  string str;
  while(cin >> str, str != "-") {
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> h;
      string s1,s2;
      s1.assign(str, 0,  h);
      s2.assign(str,h,str.size()-h);
      str = s2 + s1;
    }
    cout << str << endl;
  }
  return 0;
}
