#include <stdio.h>
#include <stdlib.h>

void cal_fibonacci(long *a,int n) {
   a[0] =  1;
   if(n > 0) a[1] =  1;
   int i;
   for (i = 2; i <= n; i++) {
     a[i] = a[i-1] + a[i-2];
   }
}

int main()
{
  int n;
  long *a;
  scanf("%d",&n);
  a = malloc(sizeof(long) * (n+1));
  cal_fibonacci(a,n);
  printf("%ld\n",a[n]);
  return 0;
}
