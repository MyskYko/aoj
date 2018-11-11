#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define h 0.001
void ndsolve(double (*)(double, double), double, double, double);
/*RL回路の微分方程式(ODE)右辺*/
double RL(double i, double t) {
  if(t >= 1 && t < 2) {
    return i + h * (1-i);
  }
  return i - h * i;
}
int main() {
ndsolve(RL, 0, 0, 10); // 数値的に解く
return 0;
}
void ndsolve(double (*f)(double, double), double x0, double t0, double tend) {
/*埋める*/
  double x,t;
  t = t0;
  x = x0;
  while (t <= tend) {
    printf("%lf\t%lf\n",t,x);
    x = f(x,t);
    t+=h;
  }
}
