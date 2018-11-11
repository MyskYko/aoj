#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i,H;
  long *A;
  scanf("%d",&H);
  A = (long*)malloc(sizeof(long) * (H+1));
  for (i = 1; i <= H; i++) {
    scanf("%ld",A+i);
  }
for (i = 1; i <= H; i++) {
  printf("node %d: key = %ld, ",i,A[i]);
  if(i/2 > 0) printf("parent key = %ld, ", A[i/2]);
  if(2*i <= H) printf("left key = %ld, ", A[2*i]);
  if(2*i+1 <= H) printf("right key = %ld, ", A[2*i+1]);
  printf("\n");
 }

  return 0;
}
