#include <stdio.h>

int main() {
  long a,b,temp;
  scanf("%ld %ld", &a, &b);

  if(b>a) {
    temp = a;
    a = b;
    b = temp;
  }
  while(b != 0) {
    temp = b;
    b = a%b;
    a = temp;
  }
  printf("%ld\n", a);

  return 0;
}
