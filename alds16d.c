#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int swap_log[1000][2];

void swap(int *A, int i, int j) {
  int temp;
  temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

void Merge(int *A, int left, int mid, int right) {
  int n1,n2,*L,*R,i,j,k;
  n1 = mid -left;
  n2 = right - mid;
  L = (int*)malloc(sizeof(int) * (n1+1));
  R = (int*)malloc(sizeof(int) * (n2+1));
  for (i = 0; i< n1; i++) L[i] = A[left+i];
  for (i = 0; i < n2; i++) R[i] = A[mid+i];
  L[n1] = INT_MAX; R[n2] = INT_MAX;
  i = 0;j = 0;
  for(k = left; k < right; k++) {
    if (L[i] < R[j]) {
      A[k] = L[i];
      i++;
    }else {
      A[k] = R[j];
      j++;
    }
  }
  free(L);
  free(R);
}

void Merge_Sort(int *A, int left, int right) {
  if(left+1 < right) {
    int mid = (left + right)/2;
    Merge_Sort(A,left,mid);
    Merge_Sort(A,mid,right);
    Merge(A,left,mid,right);
  }
}
long step_sort(int *w, int *w1, int i) {
  int j,k;
  long sum = 0;
  k = 0;
  while(w[i] != w1[i]) {
    j = 0;
    while (w[j] != w1[i]) j++;
    sum += w[i]+w[j];
    swap(w,i,j);
    swap_log[k][0] = i; swap_log[k][1] = j;
    i = j;
    k++;
  }
  swap_log[k][0] = 0; swap_log[k][1] = 0;
  return sum;
}

int search_min(int *w, int *w1,int n) {
  int i,j;
  i = 0;
  while(1) {
    j = 0;
    while(w[j] != w1[i]) j++;
    if(i != j) break;
    i++;
    if(i >= n) return n;
  }
  return j;
}

long run_log(int *w) {
  int i = 0;
  long sum = 0;
  while(swap_log[i][0] != swap_log[i][1]) {
    sum += w[swap_log[i][0]]+w[swap_log[i][1]];
    swap(w,swap_log[i][0],swap_log[i][1]);
    i++;
  }
  return sum;
}

long sub_sort(int *w, int *w1, int i) {
  long sum;

  if(w[0] != w1[0]) return LONG_MAX;
  int j = 0;
  while(w[i] != w1[j]) j++;
  sum = w[i] + w[0];
  swap(w,i,0);
  sum += run_log(w);
  sum += w[0] + w[j];
  swap(w,0,j);
  
  return sum;
}

long repeat_sort(int *w, int *w1, int n,long now) {
  int i;
  int a1[n];
  long v1,v2;
  for (i = 0; i < n; i++) a1[i]=w[i];
  i = search_min(w,w1,n);
  if(i == n) return now;
  v1 = step_sort(w,w1,i);
  v2 = sub_sort(a1,w1,i);
  long min = (v1 < v2) ? v1:v2;
  return repeat_sort(w,w1,n,now+min);
}

long much_sort(int *w, int *w1, int n) {
  int i,j;
  long sum = 0;
  char *checked = (char*)calloc(n,sizeof(char));
  i = 0;
  while(i < n) {
    j = 0;
    while(w[j] != w1[i]) j++;
    if(i != j) {
      if(w1[j] ==  w[i]) {
	sum += w[i] + w[j];
	swap(w,i,j);
      }
    }
    checked[i]=1;checked[j]=1;
    while(i < n && checked[i]!=0)i++;
  }
  free(checked);
  return sum;
}

int main()
{
  int i,n,*w,*w2;
  long sum;
  scanf("%d",&n);
  w = (int*)malloc(sizeof(int) * n);
  w2 = (int*)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    scanf("%d",w+i);
    w2[i] = w[i];
  }
  Merge_Sort(w2,0,n);
  
  sum = much_sort(w,w2,n);
  sum += repeat_sort(w,w2,n,0);
  printf("%ld\n",sum);
  
  return 0;
}
