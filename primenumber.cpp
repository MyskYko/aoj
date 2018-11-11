#include <cstdio>
#include <cstdlib>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)

int main() {
  int prime_flag[1000000];
  FOR(i, 2, 1000000) prime_flag[i] = 1;
  int t = 2;
  while(t < 1000000/2) {
    if(prime_flag[t]) {
      int k = 2;
      while(t * k < 1000000) {
	prime_flag[t*k] = 0;
	k++;
      }
    }
    t++;
  }
  int n;
  while(scanf("%d", &n) != EOF) {
    t = 0;
    REP(i, n+1) t += prime_flag[i];
    printf("%d\n", t);
  }
  
  return 0;
}
