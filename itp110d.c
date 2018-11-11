#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double minkowski(int n, int *x, int *y, int p) {
  int i;
  double d;
  d = 0;
  for(i = 0;i < n;i++) {
    d += pow(abs(x[i] - y[i]), p);
  }
  d = pow(d, 1.0/p);
  return d;
}

double chebyshev(int n, int *x, int *y) {
  int i;
  double d;
  d = 0;
  for(i = 0;i < n;i++) {
    if(d < abs(x[i] - y[i])) {
      d = abs(x[i] - y[i]);
    }
  }

  return d;
}

int main() {
  int n, i;
  scanf("%d", &n);
  int x[n], y[n];
  for(i = 0;i < n;i++) {
    scanf("%d", x+i);
  }
  for(i = 0;i < n;i++) {
    scanf("%d", y+i);
  }
  for(i = 1;i <= 3;i++) {
    printf("%lf\n", minkowski(n,x,y,i));
  }
  printf("%lf\n", chebyshev(n, x, y));

  return 0;
}
