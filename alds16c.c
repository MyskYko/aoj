#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void Merge(long *A, char *mark, long left, long mid, long right) {
  long n1,n2,*L,*R,i,j,k;
  char *L_mark,*R_mark;
  n1 = mid -left;
  n2 = right - mid;
  L = (long*)malloc(sizeof(long) * (n1+1));
  L_mark = (char*)malloc(sizeof(char) * (n1+1));
  R = (long*)malloc(sizeof(long) * (n2+1));
  R_mark = (char*)malloc(sizeof(char) * (n2+1));
  for (i = 0; i< n1; i++) {
    L[i] = A[left+i];
    L_mark[i] = mark[left+i];
  }
  for (i = 0; i < n2; i++) {
    R[i] = A[mid+i];
    R_mark[i] = mark[mid+i];
  }
  L[n1] = LONG_MAX; R[n2] = LONG_MAX;
  i = 0;j = 0;
  for(k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      mark[k] = L_mark[i];
      i++;
    }else {
      A[k] = R[j];
      mark[k] = R_mark[j];
      j++;
    }
  }
  free(L);
  free(L_mark);
  free(R);
  free(R_mark);
}

void Merge_Sort(long *A,char* mark, long left, long right) {
  if(left+1 < right) {
    long mid = (left + right)/2;
    Merge_Sort(A,mark,left,mid);
    Merge_Sort(A,mark,mid,right);
    Merge(A,mark,left,mid,right);
  }
}


void swap(long *A, long i, long j) {
  long temp;
  temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

void swap_mark(char *A, long i, long j) {
  char temp;
  temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

long Partition(long *A,char *mark, long p, long r) {
  long i,j,x;
  x = A[r];
  i = p-1;
  for(j = p; j < r; j++) {
    if(A[j] <= x) {
      i++;
      swap(A,i,j);
      swap_mark(mark,i,j);
    }
  }
  swap(A,i+1,r);
  swap_mark(mark,i+1,r);
  return i+1;
}

void Quicksort(long *A, char *mark, long p, long r) {
  if (p < r) {
    long q = Partition(A,mark,p,r);
    Quicksort(A,mark,p,q-1);
    Quicksort(A,mark,q+1,r);
  }
}

int main()
{
  long i,n,*A,*B;
  char *mark,*mark2;
  scanf("%ld ", &n);
  A = (long*)malloc(sizeof(long) * n);
  B = (long*)malloc(sizeof(long) * n);
  mark = (char*)malloc(sizeof(char) * n);
  mark2 = (char*)malloc(sizeof(char) * n);
  for (i = 0; i < n; i++) {
    scanf("%c %ld ", mark+i, A+i);
    B[i] = A[i];
    mark2[i] = mark[i];
  }

  Quicksort(A,mark,0,n-1);
  Merge_Sort(B,mark2,0,n);
  i = 0;
  while (1) {
    if(mark[i] != mark2[i]) {
      printf("Not stable\n");
      break;
    }
    if(i == n-1) {
      printf("Stable\n");
      break;
    }
    i++;
  }

  for (i = 0; i < n; i++) {
    printf("%c %ld\n",mark[i],A[i]);
  }

  return 0;
}
