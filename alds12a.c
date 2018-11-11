#include <stdio.h>



int main() {
  int n, i, j, temp, t;
  scanf("%d", &n);
  int a[n];
  for(i = 0; i < n; i++) scanf("%d", a+i);

  t=0;
  for(i = 0; i < n-1; i ++)
    for(j = n-1; j > i; j--)
      if(a[j] < a[j-1]) {
	temp = a[j];
	a[j] = a[j-1];
	a[j-1] = temp;
	t++;
      }

  for(i = 0; i < n-1; i++) printf("%d ", a[i]);
  printf("%d\n", a[i]);
  printf("%d\n", t);

  return 0;  
}
