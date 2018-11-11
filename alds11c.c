#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  unsigned char a0: 1;
  unsigned char a1: 1;
  unsigned char a2: 1;
  unsigned char a3: 1;
  unsigned char a4: 1;
  unsigned char a5: 1;
  unsigned char a6: 1;
  unsigned char a7: 1;
}boolean;

void set_boolean(boolean *bool, int ad, char in) {
  switch (ad) {
  case 0:
    bool->a0 = in;
    break;
  case 1:
    bool->a1 = in;
    break;
  case 2:
    bool->a2 = in;
    break;
  case 3:
    bool->a3 = in;
    break;
  case 4:
    bool->a4 = in;
    break;
  case 5:
    bool->a5 = in;
    break;
  case 6:
    bool->a6 = in;
    break;
  case 7:
    bool->a7 = in;
    break;
  default:
    break;
  }
}

char check_boolean(boolean *bool, int ad) {
  switch (ad) {
  case 0:
    return bool->a0;
    break;
  case 1:
    return bool->a1;
    break;
  case 2:
    return bool->a2;
    break;
  case 3:
    return bool->a3;
    break;
  case 4:
    return bool->a4;
    break;
  case 5:
    return bool->a5;
    break;
  case 6:
    return bool->a6;
    break;
  case 7:
    return bool->a7;
    break;
  default:
    printf("miss");
    return 0;
    break;
  }
}

void sieve(boolean *list, long max) {
  int i,j;
  long k;

  for(k = 0; k <= max; k++)
    set_boolean(list+k/8, (int)(k%8), 0);

  
  list[0].a0 = 1;
  list[0].a1 = 1;

  for(i = 2; 2*i <= max; i++)
    set_boolean(list+i/4, (2*i)%8, 1);
  
  for(i = 3; i <= (int)sqrt(max); i++)
    if(check_boolean(list+i/8,(int)i%8) == 0)
      for(j = i; i*(long)j <= max; j+=2)
	set_boolean(list+i*j/8,(int)(i*j%8), 1);
  
}

int main() {
  int N,i,t;
  scanf("%d", &N);
  long a[N],max;
  max = 0;
  for(i = 0; i < N; i++) {
    scanf("%ld", a+i);
    if(a[i] > max) max = a[i];
  }
  
  boolean *list;
  list = (boolean *)malloc(sizeof(boolean)*(max/8+1));
  sieve(list,max);

  t = 0;
  for(i = 0; i < N; i++) {
    if(check_boolean(list+a[i]/8, (int)a[i]%8) == 0) t++;
  }
  printf("%d\n", t);

  free(list);
  return 0;
}
