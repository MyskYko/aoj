#include <cstdio>
#include <algorithm>
#include <functional>
#include <stack>
#include <cmath>
using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define llong long long

int main() {
  double v;
  while(scanf("%lf",&v) != EOF) {
    double t = v/9.8;
    double d = 4.9*t*t;
    double dover5 = d/5;
    int N = (dover5-(int)dover5 == 0)? (int)dover5+1: (int)dover5+2;
    printf("%d\n", N);
  }
  return 0;
}
