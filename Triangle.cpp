#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
  int a,b,C;
  double S,L,h;
  cin >> a >> b >> C;
  S = a*b*sin(C*M_PI/180)/2;
  L = a+b+sqrt(a*a + b*b - 2*a*b*cos(C*M_PI/180));
  h = b*sin(C*M_PI/180);
  cout << fixed << setprecision(4) << S << endl << L << endl << h << endl;
  return 0;
}
