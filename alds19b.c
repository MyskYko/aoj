#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(long *A, long i, long j) {
  long tmp;
  tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
}

void maxHeapify(long *A, long i,long H) {
  long l,r,largest;
  l = 2*i;
  r = 2*i+1;
  if(l <= H && A[l] > A[i]) largest = l;
  else largest = i;
  if(r <= H && A[r] > A[largest]) largest = r;
  if(largest != i) {
    swap(A,i,largest);
    maxHeapify(A,largest,H);
  }
}

void buildMaxHeap(long *A,long H) {
  long i;
  for(i = H/2; i > 0; i--) maxHeapify(A,i,H);
}

int main()
{
  int i,H;
  long *A;
  scanf("%d",&H);
  A = (long*)malloc(sizeof(long) * (H+1));
  for (i = 1; i <= H; i++) {
    scanf("%ld",A+i);
  }
  buildMaxHeap(A,H);
  for (i = 1; i <= H; i++) {
    printf(" %ld", A[i]);
  }
  printf("\n");


  return 0;
}
