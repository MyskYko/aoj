#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int m;
long cnt,*G;

void insertionSort(long *A, long n, long g) {
  long i,j,v;
  for(i = g; i < n; i++) {
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v) {
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
}
void shellSort(long *A, long n) {
  int i;
  cnt = 0;
  m = (int)ceil(log(n)/log(2));
  if(m == 0) m = 1;
  G = (long*)malloc(sizeof(long)*m);
  for(i = 0; i < m; i++) {
    G[i] = (long)pow(2,m-1-i);
    insertionSort(A, n, G[i]);
  }
}

int main() {
  long i,n;
  scanf("%ld", &n);
  long A[n];
  for(i = 0; i < n; i++) scanf("%ld", A+i);
  shellSort(A, n);

  printf("%d\n",m);
  for(i = 0; i < m-1; i++) printf("%ld ", G[i]);
  printf("%ld\n%ld\n", G[i], cnt);
  for(i = 0; i < n; i++) printf("%ld\n", A[i]);

  free(G);
  return 0;
}
