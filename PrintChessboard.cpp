#include <iostream>
using namespace std;

int main()
{
  int H,W;
  while(cin >> H >> W, H!=0 || W!=0) {
    for(int j = 0; j < H; j++) {
      for(int i = 0; i < W; i++) {
	if((i+j)%2 == 0) cout << "#";
	else cout << ".";
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
