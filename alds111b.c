#include <stdio.h>
#include <stdlib.h>

void search(int **a, int n, int *d, int *f, int u, int *t) {
  int i;
  d[u] = *t;
  (*t)++;
  for (i = 0; i < n; i++) {
    if(a[u][i] == 1 && d[i] == 0) {
      search(a,n,d,f,i,t);
    }
  }
  f[u] = *t;
  (*t)++;	
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

  int *d,*f,t;
  d = (int*)calloc(n,sizeof(int));
  f = (int*)calloc(n,sizeof(int));
  t = 1;

  for (i = 0; i < n; i++) {
    if(d[i] == 0) {
      search(a,n,d,f,i,&t);
    }
  }


  for (i = 0; i < n; i++) {
    printf("%d ", i+1);
    printf("%d ", d[i]);
    printf("%d\n", f[i]);
  }

  free(a);
  free(d);
  free(f);
  return 0;
}
