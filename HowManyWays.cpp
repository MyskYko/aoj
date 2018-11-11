#include <iostream>
using namespace std;

int main()
{
  int n,x;
  while(cin >> n >> x, n != 0 || x != 0) {
    int t = 0;
    for(int i = 1; i <= n-2; i++) {
      for(int j = i+1; j <= n-1; j++) {
	if(x-i-j > j && x-i-j <= n) t++;
	else if(x-i-j < j) break;
      }
    }
    cout << t << endl;
  }
  return 0;
}

