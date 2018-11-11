#include <stdio.h>
#include <stdlib.h>

void search(int **a, int n, int *d, int u, int t) {
  if(d[u] != 0 && d[u] < t) return;
  d[u] = t;
  int i;
  for (i = 1; i < n; i++) {
    if(a[u][i] == 1) {
      search(a,n,d,i,t+1);
    }
  }
}

int main()
{
  int i,j,n,**a,u,k,v;
  scanf("%d",&n);
  a = (int**)malloc(sizeof(int*) * n);
  for (i = 0; i < n; i++) {
    a[i] = (int*)malloc(sizeof(int) * n);
    for(j = 0; j < n; j++) a[i][j] = 0;
  }
  for (i = 0; i < n; i++) {
    scanf("%d",&u);
    scanf("%d", &k);
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      a[u-1][v-1] = 1;
    }
  }

  int *d;
  d = (int*)calloc(n,sizeof(int));

  search(a,n,d,0,0);
  for (i = 1; i < n; i++) {
    if(d[i] == 0) d[i] = -1;
  }



  for (i = 0; i < n; i++) {
    printf("%d ", i+1);
    printf("%d\n", d[i]);
  }

  free(a);
  free(d);
  return 0;
}
