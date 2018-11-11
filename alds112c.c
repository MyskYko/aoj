#include <stdio.h>
#include <stdlib.h>

void step(int **G, long **cost, char *flag, int u, long *d) {
  int i,j;
  long t = d[u];
  for (i = 0;; i++) {
    j = G[u][i];
    if(j == -1) break;
    if(d[j] == -1 || d[j] > t+cost[u][i]) {
      flag[j] = 1;
      d[j] = t+cost[u][i];
    }
  }
}

void solve(int **G, long **cost, int n, long *d) {
  int i,j;
  char *flag,*new_flag;
  flag = (char*)malloc(sizeof(char) * n);
  new_flag = (char*)malloc(sizeof(char) * n);
  flag[0] = 1;
  for (i = 1; i < n; i++) flag[i] = 0;
  while(1) {
    for (i = 0; i < n; i++) new_flag[i] = 0;
    for (i = 0; i < n; i++) 
      if(flag[i] == 1) step(G,cost,new_flag,i,d);
    j = 0;
    for (i = 0; i < n; i++) {
      j += new_flag[i];
      flag[i] = new_flag[i];
    }
    if(j == 0) break;
  }
    
  return;
}

void sort(long *A, int *B, int a, int b){
  if(b == a+1) return;
  int m = a+(b-a)/2;
  sort(A,B,a,m);
  sort(A,B,m,b);
  int i,j,t;
  long *newA;
  int *newB;
  newA = (long*)malloc(sizeof(long)*(b-a));
  newB = (int*)malloc(sizeof(int) * (b-a));
  if(b-a == 0) printf("a");
  i = 0;j = 0;t = 0;
  while(t < b-a) {
    if((a+i < m && A[a+i] < A[m+j]) || m+j == b) {
      newA[t] = A[a+i];
      newB[t] = B[a+i];
      i++;
    }
    else{
      newA[t] = A[m+j];
      newB[t] = B[m+j];
      j++;
    }
    t++;
  }
  for (i = 0; i < b-a; i++) {
    A[a+i] = newA[i];
    B[a+i] = newB[i];
  }
  free(newA);
  free(newB);
}

int main()
{
  int n;
  int i,j,u,k,v;
  int **G;
  long **cost,c;
  long *d;
  scanf("%d",&n);
  G = (int**)malloc(sizeof(int*) * n);
  cost = (long**)malloc(sizeof(long*) * n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &u, &k);
    G[u] = (int*)malloc(sizeof(int) * (k+1));
    cost[u] = (long*)malloc(sizeof(long) * k);
    for (j = 0; j < k; j++) {
      scanf("%d %ld", &v, &c);
      G[u][j] = v;
      cost[u][j] = c;
    }
    if(k != 0)sort(cost[u],G[u],0,k);
    G[u][k] = -1;
  }
  d = (long*)malloc(sizeof(long) * n);
  d[0] = 0;
  for (i = 1; i < n; i++) {
    d[i] = -1;
  }
  solve(G,cost,n,d);
  for (i = 0; i < n; i++) {
    printf("%d %ld\n", i, d[i]);
  }
  return 0;
}
