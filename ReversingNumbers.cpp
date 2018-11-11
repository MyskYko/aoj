#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cout << a[n-i-1];
    if(i != n-1) cout << " ";
    else cout << endl;
  }
  return 0;
}
