#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long count = 0;

void Merge(long *A, long left, long mid, long right) {
  long n1,n2,*L,*R,i,j,k;
  n1 = mid -left;
  n2 = right - mid;
  L = (long*)malloc(sizeof(long) * (n1+1));
  R = (long*)malloc(sizeof(long) * (n2+1));
  for (i = 0; i< n1; i++) {
    L[i] = A[left+i];
  }
  for (i = 0; i < n2; i++) {
    R[i] = A[mid+i];
  }
  L[n1] = LONG_MAX; R[n2] = LONG_MAX;
  i = 0;j = 0;
  for(k = left; k < right; k++) {
    if (L[i] < R[j]) {
      A[k] = L[i];
      i++;
    }else {
      A[k] = R[j];
      j++;
    }
    count++;
  }
  free(L);
  free(R);
}

void Merge_Sort(long *A, long left, long right) {
  if(left+1 < right) {
    long mid = (left + right)/2;
    Merge_Sort(A,left,mid);
    Merge_Sort(A,mid,right);
    Merge(A,left,mid,right);
  }
}

int main()
{
  long i,n,*S;
  scanf("%ld", &n);
  S = (long*)malloc(sizeof(long) * n);
  for (i = 0; i < n; i++) {
    scanf("%ld", S+i);
  }
  Merge_Sort(S,0,n);
  for (i = 0; i < n-1; i++) {
    printf("%ld ", S[i]);
  }
  printf("%ld\n", S[i]);
  printf("%ld\n", count);
  return 0;
}
