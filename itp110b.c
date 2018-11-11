#include <stdio.h>
#include <math.h>

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  double degree, s, l ,h;
  degree = M_PI * c / 180;
  s = a * b * sin(degree) / 2;
  l = a + b + sqrt(a*a + b*b - 2*a*b*cos(degree));
  h = b * sin(degree);
  printf("%lf\n%lf\n%lf\n", s, l, h);

  return 0;
}
