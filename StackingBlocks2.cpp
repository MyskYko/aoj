#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  vector <vector<char> > v;
  vector<char> removed;
  string order;
  int n;
  cin >> n;
  v.resize(n);
  while(cin >> order, order != "quit") {
    if(order == "push") {
      int p;
      char color;
      cin >> p >>color;
      v[p-1].push_back(color);
    }
    else if(order == "pop") {
      int p;
      cin >> p;
      removed.push_back(v[p-1].back());
      v[p-1].pop_back();
    }
    else if(order == "move") {
      int p1,p2;
      cin >> p1 >> p2;
      v[p2-1].push_back(v[p1-1].back());
      v[p1-1].pop_back();
    }
  }
  for (int i = 0; i < (int)removed.size(); i++) {
    cout << removed[i] << endl;
  }
  return 0;
}
