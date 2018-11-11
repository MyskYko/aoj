#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define h 0.001
void ndsolve(double (**)(double*, double), double*, double, double,int);

double rossler0(double* a, double t) {
  return a[0] + h * (-a[1]-a[2]);
}
double rossler1(double* a, double t) {
  return a[1] + h * (a[0]+0.15*a[1]);
}
double rossler2(double* a, double t) {
  return a[2] + h * (0.2+a[2]*(a[0]-7.1));
}

int main() {
  double (**f)(double*, double);
  f = (double (**)(double*,double))malloc(sizeof(double(*)(double*,double)) * 3);
  f[0] = rossler0;
  f[1] = rossler1;
  f[2] = rossler2;
  double *a = (double*)malloc(sizeof(double) * 3);
  a[0] = 0;a[1] = 0; a[2] = 0;
  
  ndsolve(f, a, 0, 1000,3); // 数値的に解く
  return 0;
}
void ndsolve(double (**f)(double*, double), double* x0, double t0, double tend,int N) {
/*埋める*/
  double x[N],x_next[N],t;
  int i;
  for (i = 0; i < N; i++) x[i] = x0[i];
  t = t0;
  while (t <= tend) {
    printf("%lf\t",t);
    for (i = 0; i < N-1; i++) printf("%lf\t", x[i]);
    printf("%lf\n", x[i]);
    for (i = 0; i < N; i++) x_next[i] = f[i](x,t);
    for (i = 0; i < N; i++) x[i] = x_next[i];
    t+=h;
  }
}
