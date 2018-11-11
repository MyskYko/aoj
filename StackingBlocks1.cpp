#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  vector<char> v,removed;
  string order;
  char color;
  while(cin >> order, order != "quit") {
    if(order == "push") {
      cin >> color;
      v.push_back(color);
    }
    else if(order == "pop") {
      removed.push_back(v.back());
      v.pop_back();
    }
  }
  for (int i = 0; i < (int)removed.size(); i++) {
    cout << removed[i] << endl;
  }
  return 0;
}
