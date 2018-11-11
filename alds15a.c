#include <stdio.h>
#include <stdlib.h>

int check(int n, int m, int *A, int M, long sum) {
  if(m == n) {
    if (sum == M) {
      return 1;
    }
    return 0;
  }
  int v0 = check(n,m+1,A,M,sum);
  if (v0 == 1) {
    return 1;
  }
  if (sum + A[m] <= M) {
    int v1 = check(n,m+1,A,M,sum+A[m]);
    if (v1 == 1) {
      return 1;
    }    
  }

  return 0;
}

  

int main()
{
  int i,n,*A,q,M;
  scanf("%d",&n);
  A = (int*)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    scanf("%d",A+i);
  }
  scanf("%d",&q);
  for (i = 0; i < q; i++) {
    scanf("%d",&M);
    if(check(n,0,A,M,0) == 1) {
      printf("yes\n");
    }else {
      printf("no\n");
    }
  }
  
  
  return 0;
}
