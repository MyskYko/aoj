#include <stdio.h>
#include <stdlib.h>

void solve(long **G, int n, int u, long *d, int t) {
  int i,j;
  int *flag;
  j = 0;
  flag = (int*)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    if(G[u][i] != -1 && (d[i] == -1 || d[i] > t+G[u][i])) {
      flag[j] = i;
      j++;
      d[i] = t+G[u][i];
    }
  }
  for (i = 0; i < j; i++) {
      solve(G,n,flag[i],d,t+G[u][flag[i]]);
  }
  free(flag);
}

int main()
{
  int n;
  int i,j,u,k,v;
  long **G,c;
  long *d;
  scanf("%d",&n);
  G = (long**)malloc(sizeof(long*) * n);
  for (i = 0; i < n; i++) {
    G[i] = (long*)malloc(sizeof(long) * n);
    for(j = 0; j < n; j++) G[i][j] = -1;
  }
  for (i = 0; i < n; i++) {
    scanf("%d %d", &u, &k);
    for (j = 0; j < k; j++) {
      scanf("%d %ld", &v, &c);
      G[u][v] = c;
    }
  }
  d = (long*)malloc(sizeof(long) * n);
  d[0] = 0;
  for (i = 1; i < n; i++) {
    d[i] = -1;
  }
  solve(G,n,0,d,0);
  for (i = 0; i < n; i++) {
    printf("%d %ld\n", i, d[i]);
  }
  return 0;
}
