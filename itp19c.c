#include <stdio.h>



int diccmp(char *a, char *b) {
  int i=0;
  while(1) {
    if(a[i] == '\0' && b[i] == '\0') return 0;
    if(a[i] > b[i]) return 1;
    if(a[i] < b[i]) return 2;
    i++;
  }
}


int main() {
  int n,tp,hp;
  char taro[101], hanako[101];

  tp = 0; hp = 0;
  scanf("%d", &n);
  for(; n > 0; n--) {
    scanf("%s %s", taro, hanako);
    switch (diccmp(taro, hanako)) {
    case 0:
      tp++;
      hp++;
      break;
    case 1:
      tp += 3;
      break;
    case 2:
      hp += 3;
      break;
    }
  }
  
  printf("%d %d\n", tp, hp);
  return 0;
}
