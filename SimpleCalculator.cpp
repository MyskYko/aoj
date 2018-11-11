#include <iostream>
using namespace std;

int main()
{
  int a,b;
  char c;
  while(cin >> a >> c >> b, c != '?') {
    if(c == '+') cout << a+b << endl;
    else if(c == '-') cout << a-b << endl;
    else if(c == '*') cout << a*b << endl;
    else cout  << a/b << endl;
  }
  return 0;
}
