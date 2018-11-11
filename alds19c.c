#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(long *A, long i, long j) {
  long tmp;
  tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
}

void up_heap(long *A, long i,long H) {
  long l,r,largest;
  if(i <= 0) return;
  l = 2*i;
  r = 2*i+1;
  if(l <= H && A[l] > A[i]) largest = l;
  else largest = i;
  if(r <= H && A[r] > A[largest]) largest = r;
  if(largest != i) {
    swap(A,i,largest);
    up_heap(A,i/2,H);
  }
}

void down_heap(long *A, long i, long H) {
  long l,r,largest;
  if(i <= 0) return;
  l = 2*i;
  r = 2*i+1;
  if(l <= H && A[l] > A[i]) largest = l;
  else largest = i;
  if(r <= H && A[r] > A[largest]) largest = r;
  if(largest != i) {
    swap(A,i,largest);
    down_heap(A,largest,H);
  }
}

int main()
{
  long i,*A;
  char command[8];
  A = malloc(sizeof(long) * 2000000);
  i = 0;
  while (1) {
    scanf("%s",command);
    if(strcmp(command,"insert") == 0) {
      i++;
      scanf("%ld",A+i);
      up_heap(A,i/2,i);
    }
    if(strcmp(command,"extract") == 0) {
      printf("%ld\n",A[1]);
      swap(A,1,i);
      i--;
      down_heap(A,1,i);
    }
    if(strcmp(command,"end") == 0) break;
  }

  return 0;
}
