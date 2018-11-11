#include <iostream>
using namespace std;

int main()
{
  int c;
  while(c = cin.get(), c != EOF){
    if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    else if(c >= 'a' && c <= 'z') c = c - 'a' + 'A';
    cout.put(c);
  }
  return 0;
}
