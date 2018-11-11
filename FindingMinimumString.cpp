#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n;
  string str,min;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> str;
    if(min.empty() || str < min) min = str;
  }
  cout << min << endl;
  return 0;
}
