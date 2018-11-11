#include <stdio.h>

int main() {
  int N,i,j,mini,temp,t;
  scanf("%d", &N);
  int a[N];
  for(i = 0; i < N; i++) scanf("%d", a+i);

  t = 0;
  for(i = 0; i < N-1; i++) {
    mini = i;
    for(j = i+1; j < N; j++)
      if(a[mini] > a[j])
	mini = j;
    if(i != mini) {
      temp = a[i];
      a[i] = a[mini];
      a[mini] = temp;
      t++;
    }
  }

  for(i = 0; i < N-1; i++) printf("%d ", a[i]);
  printf("%d\n%d\n", a[i], t);

  return 0;
}
