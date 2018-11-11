#include <stdio.h>
#include <stdlib.h>

int check(int *x, int *y, int t) {
  int i;
  for (i = 0; i < t; i++) {
    if(x[i] == x[t]) return 1;
    if(y[i] == y[t]) return 1;
    if(x[i]+y[i] == x[t]+y[t]) return 1;
    if(x[i]-y[i] == x[t]-y[t]) return 1;
  }
  return 0;
}

void search(int *x, int *y, int *t) {
  while(*t < 8) {
    if(y[*t] == 7) {
      x[*t]++;
      y[*t] = 0;
    }
    else {
      y[*t]++;
    }
    if(x[*t] > 7) {
      x[*t] = 0;
      y[*t] = -1;
      (*t)--;
    }
    else if(check(x,y,*t) == 0) {
      (*t)++;
    }

  }
}

void print_board(int *x, int *y) {
  int i,j,t;
  for (i = 0; i < 8; i++) {
    for (t = 0; i != x[t]; t++);
    for (j = 0; j < 8; j++) {
      if(j == y[t]) printf("Q");
      else printf(".");
    }
    printf("\n");
  }
}

int main()
{
  int i,t,k,*x,*y;
  x = (int*)malloc(sizeof(int) * 8);
  y = (int*)malloc(sizeof(int) * 8);
  for (i = 0; i < 8; i++) {
    x[i] = 0;
    y[i] = -1;
  }
  t = 0;
  scanf("%d",&k);
  for(i = 0; i < k; i++) {
    scanf("%d %d",x+i,y+i);
    t++;
  }

  search(x,y,&t);

  print_board(x,y);
  return 0;
}
