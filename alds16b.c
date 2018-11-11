#include <stdio.h>
#include <stdlib.h>

void swap(long *A, long i, long j) {
  long temp;
  temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

long Partition(long *A, long p, long r) {
  long i,j,x;
  x = A[r];
  i = p-1;
  for(j = p; j < r; j++) {
    if(A[j] <= x) {
      i++;
      swap(A,i,j);
    }
  }
  swap(A,i+1,r);

  return i+1;
}

int main()
{
  long i,n,q,*A;
  scanf("%ld", &n);
  A = (long*)malloc(sizeof(long) * n);
  for (i = 0; i < n; i++) {
    scanf("%ld",A+i);
  }
  q = Partition(A,0,n-1);
  for (i = 0; i < q; i++) {
    printf("%ld ",A[i]);
  }
  printf("[%ld] ",A[i]);
  for (i = q+1; i < n-1; i++) {
    printf("%ld ",A[i]);
  }
  printf("%ld\n",A[i]);
  return 0;
}
