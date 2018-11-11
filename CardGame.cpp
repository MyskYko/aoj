#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n,taro,hanako;
  cin >> n;
  string st,sh;
  taro = 0;
  hanako = 0;
  for(int i = 0; i < n; i++) {
    cin >> st >> sh;
    if(st > sh) taro += 3;
    else if(st < sh) hanako += 3;
    else if(st == sh) {
      taro++;
      hanako++;
    }
  }
  cout << taro << " " << hanako << endl;
  return 0;
}
