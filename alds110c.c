#include <stdio.h>
#include <string.h>


int max(int a, int b) {
  return (a > b)?a:b;
}

int solve(char *a, char *b, int al, int bl) {
  int i,j;
  int table[al+1][bl+1];
  for (i = 0; i <= al; i++) {
    table[i][0] = 0;
  }
  for (i = 0; i <= bl; i++) {
    table[0][i] = 0;
  }
  for (i = 1; i <= al; i++) {
    for (j = 1; j <=
	   bl; j++) {
      if(a[i-1] == b[j-1]) table[i][j] = table[i-1][j-1]+1;
      else table[i][j] = max(table[i-1][j], table[i][j-1]);
    }
  }
  return table[al][bl];
}

int main()
{
  int i,q,al,bl;
  char a[1001],b[1001];
  scanf("%d ",&q);
  for (i = 0; i < q; i++) {
    scanf("%s %s",a,b);
    al = strlen(a);
    bl = strlen(b);
    printf("%d\n",solve(a,b,al,bl));
  }
  return 0;
}
