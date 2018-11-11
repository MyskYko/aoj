#include <stdio.h>
#include <stdlib.h>

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

  for (i = 0; i < n; i++) {
    for(j = 0; j < n-1; j++) printf("%d ", a[i][j]);
    printf("%d\n",a[i][j]);
  }

  
  return 0;
}
