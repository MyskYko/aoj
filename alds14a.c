#include <stdio.h>

int main() {
  int n,q,i,j,C;
  scanf("%d", &n);
  long S[n];
  for(i = 0; i < n; i++) scanf("%ld", S+i);
  scanf("%d", &q);
  long T;C = 0;
  for(i = 0; i < q; i++) {
    scanf("%ld",&T);
    for(j = 0; j < n; j++) if(T == S[j]) { C++;break;}
  }

  printf("%d\n",C);
  
  return 0;
}
