#include <stdio.h>

int main() {
  long n,r,rj,ri,max;
  scanf("%ld", &n);
  scanf("%ld", &r);
  rj = r;
  ri = r;
  n--;
  max = -1000000000;
  for(; 0 < n; n--) {
    scanf("%ld", &r);
    if(max <= 0) {
      ri = rj;
      rj = r;
    }else{
      if(r > rj) rj = r;
      if(r < ri) {
	ri = r;
	rj = r;
      }
    }
    if(rj - ri > max) max = rj - ri;
  }

  printf("%ld\n", max);
  
  return 0;
}
