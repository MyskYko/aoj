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
  char c;
  while((c = getc(stdin)) != EOF) {
    if(c <= 'z' && c >= 'a') putc(c-'a'+'A',stdout);
    else putc(c,stdout);
  }
  
  return 0;
}
