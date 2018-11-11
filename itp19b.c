#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void shuffle(int h, char *s0) {
  int length;
  length = strlen(s0);
  char temp[length-h+1],s1[length+1];
  strcpy(temp,s0+h);
  strncpy(s1, s0, h);
  s1[h]='\0';
  sprintf(s0, "%s%s", temp, s1);
}


int main() {
  int i,h;
  char s0[201];
  while(1) {
    scanf("%s", s0);
    if(strcmp(s0, "-") == 0) break;
    scanf("%d", &i);
    for(;i>0;i--){
      scanf("%d", &h);
      shuffle(h, s0);
    }
    printf("%s\n", s0);
    memset(s0, '\0', 200);
  }
  return 0;
}
