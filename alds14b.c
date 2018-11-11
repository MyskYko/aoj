#include <stdio.h>
#include <stdlib.h>

int main() {
  long n,q,i,j,C;
  char *S;
  scanf("%ld", &n);
  S = (char*)calloc(1000000001,sizeof(char));
  for(i = 0; i < n; i++) { scanf("%ld", &j); S[j]=1;}
  scanf("%ld", &q);
  long T;C = 0;
  for(i = 0; i < q; i++) {
    scanf("%ld",&T);
    if(S[T] == 1) C++;
  }

  printf("%ld\n",C);

  free(S);
  return 0;
}
