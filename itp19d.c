#include <stdio.h>
#include <string.h>

void printstr(int a, int b, char *str) {
  int length = strlen(str);
  char s[length+1];
  strncpy(s, str+a, b-a+1);
  s[b-a+1] = '\0';
  printf("%s\n", s);
}

void reversestr(int a, int b, char *str) {
  int length = strlen(str);
  char s[length+1];
  strcpy(s, str);
  int i;
  for(i = 0; i < b-a+1; i++) {
    str[a+i] = s[b-i];
  }
}

void replacestr(int a, int b, char *str, char *p) {
  int i;
  for(i = 0; i < b-a+1; i++) {
    str[a+i] = p[i];
  }
}

int main() {
  int a, b;
  char str[1001], command[8], p[1001];
  scanf("%s", str);
  int q;
  scanf("%d", &q);
  for(; q > 0; q--) {
    scanf("%s %d %d", command, &a, &b);
    if(strcmp(command,"print") == 0) {
      printstr(a, b, str);
    }
    if(strcmp(command,"reverse") == 0) {
      reversestr(a, b, str);
    }
    if(strcmp(command,"replace") == 0) {
      scanf("%s", p);
      replacestr(a, b, str, p);
    }
  }

  return 0;
}
