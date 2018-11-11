#include <iostream>
using namespace std;

int main()
{
  int a,t;
  t = 0;
  while(cin >> a, a) {
    t++;
    cout << "Case " << t << ": " << a << endl;
  }
  return 0;
}
