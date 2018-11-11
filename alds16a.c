#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void counting_sort(int *A, int *B, int k, long n) {
  int i;
  long j,C[k+1];
  
  for (i = 0; i <= k; i++) {
    C[i] = 0;
  }
  for (j = 1; j <= n; j++) {
    C[A[j]]++;
  }
  for (i = 1; i <= k; i++) {
    C[i] += C[i-1];
  }
  for (j = n; j >= 1; j--) {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

int main()
{
  long i,n;
  int *A,*B,k;
  scanf("%ld",&n);
  A = (int*)malloc(sizeof(int) * (n+1));
  B = (int*)malloc(sizeof(int) * (n+1));
  k = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d",A+i);
    if(k < A[i]) k = A[i];
  }
  counting_sort(A,B,k,n);

   for (i = 1; i < n; i++) {
     printf("%d ",B[i]);
   }
   printf("%d\n",B[i]);
  
  return 0;
}
