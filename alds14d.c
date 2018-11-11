#include <stdio.h>
#include <stdlib.h>

long check_P(long k, long *num, int *w) {
  long i,j,l,m,max = 0;
  l = 0;
  for(i = 0; i < k; i++) {
    m = 0;
    for(j = 0; j < num[i]; j++) {
      m += w[l];
      l++;
    }
    if(m > max) max = m;
  }
  return m;
}

void make_

int main() {
  int *m;
  long n,k,i;
  scanf("%ld %ld", &n, &k);
  
  return 0;
}
