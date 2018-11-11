#include <stdio.h>
#include <math.h>

double stddev(int n, int *s) {
  int i;
  double ave, dev;

  ave = 0;
  for(i = 0;i < n;i++) {
    ave += s[i];
  }
  ave /= n;
  dev = 0;
  for(i = 0;i < n;i++) {
    dev += pow(s[i] - ave, 2);
  }
  dev /= n;
  
  return sqrt(dev);
}

			       

int main() {
  int n,i;
  while(1) {
    scanf("%d", &n);
    if(n == 0) break;
    int s[n];
    for(i = 0;i < n;i++) {
      scanf("%d", s+i);
    }
    printf("%lf\n", stddev(n, s));
  }

  return 0;
}
