#include <stdio.h>
#include <string.h>

int main() {
  int t=0,length,i;
  char w[11],T[1001];
  scanf("%s", w);
  while(1) {
    scanf("%s", T);
    if(strcmp(T, "END_OF_TEXT") == 0) break;
    length = strlen(T);
    for(i = 0; i < length; i++) {
      if(T[i] >= 'A' && T[i] <= 'Z') {
	T[i] += 'a' - 'A';
      }
    }
    if(strcmp(w, T) == 0) {
      t++;
    }
    memset(T, '\0', 1000);
  }
  printf("%d\n", t);
  
  return 0;
}
