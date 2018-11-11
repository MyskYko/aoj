#include <cstdio>
#include <algorithm>
#include <functional>
#include <stack>
#include <cmath>
#include <map>
using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define llong long long

int main() {
  map<int,map<int,int> > cell;
  FOR(i,-2,12) {
    FOR(j,-2,12) {
      cell[i][j] = 0;
    }
  }
  int x,y,s;
  while(scanf("%d,%d,%d", &x, &y, &s) != EOF) {
    if(s == 1) {
      cell[x][y-1]++;
      cell[x-1][y]++;
      cell[x][y]++;
      cell[x+1][y]++;
      cell[x][y+1]++;
    }
    else if(s == 2) {
      FOR(i,-1,2) {
	FOR(j,-1,2) {
	  cell[x+i][y+j]++;
	}
      }
    }
    else if(s == 3) {
      cell[x][y-2]++;
      cell[x-2][y]++;
      cell[x+2][y]++;
      cell[x][y+2]++;
      FOR(i,-1,2) {
	FOR(j,-1,2) {
	  cell[x+i][y+j]++;
	}
      }
    }
  }

  int numzero = 0;
  int maxvalue = 0;
  REP(i,10) {
    REP(j,10) {
      if(cell[i][j] == 0) numzero++;
      if(cell[i][j] > maxvalue) maxvalue = cell[i][j];
    }
  }
  printf("%d\n%d\n",numzero,maxvalue);
  return 0;
}
