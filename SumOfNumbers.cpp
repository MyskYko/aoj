#include <iostream>
using namespace std;

int main()
{
  int c,sum;
  sum = 0;
  while(c = cin.get(), c != '0' || sum != 0){
    if(c != '\n') sum += c - '0';
    else {
      cout << sum << endl;
      sum = 0;
    }
  }
  return 0;
}
