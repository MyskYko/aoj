#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *flag;
int head,rear;
int *que;
int factorial[10];

int cal_factorial(int n) {
  if(n == 0) return 1;
  return cal_factorial(n-1)*n;
}

int stotag(char *s) {
  int tag = 0;
  int i;
  for(i = 0; i < 9; i++) {
    int t,j;
    t = 0;
    for(j = 0; j < i; j++) {
      if(s[j] < s[i]) t++;
    }
    tag += factorial[8-i]*(s[i]-'0'-t);
  }
  return tag;
}

char *tagtos(int tag) {
  int i;
  char *s;
  s = (char*)malloc(sizeof(char)*10);
  for(i = 0; i < 9; i++) {
    s[i] = tag%factorial[9-i]/factorial[8-i] + '0';
  }
  s[9] = '\0';
  for(i = 7; i >= 0; i--) {
    int j;
    for(j = 8; j > i; j--) {
      if(s[i] <= s[j]) s[j]++;
    }
  }
  return s;
}


char *move_up(char s[], int x) {
  if(x < 3) return NULL;
  char *s_new;
  s_new = (char*)malloc(sizeof(char)*10);
  strcpy(s_new,s);
  s_new[x] = s[x-3];
  s_new[x-3] = s[x];
  return s_new;
}

char *move_left(char s[], int x) {
  if(x%3 == 0) return NULL;
  char *s_new;
  s_new = (char*)malloc(sizeof(char)*10);
  strcpy(s_new,s);
  s_new[x] = s[x-1];
  s_new[x-1] = s[x];
  return s_new;
}

char *move_right(char s[], int x) {
  if(x%3 == 2) return NULL;
  char *s_new;
  s_new = (char*)malloc(sizeof(char)*10);
  strcpy(s_new,s);
  s_new[x] = s[x+1];
  s_new[x+1] = s[x];
  return s_new;
}

char *move_down(char s[], int x) {
  if(x > 5) return NULL;
  char *s_new;
  s_new = (char*)malloc(sizeof(char)*10);
  strcpy(s_new,s);
  s_new[x] = s[x+3];
  s_new[x+3] = s[x];
  return s_new;
}

int create(char s[], int t) {
  if(strcmp(s,"123456780") == 0) return t;
  int tag = stotag(s);
  if(flag[tag]) return 0;
  flag[tag] = t;
  que[rear] = tag;
  rear++;
  return 0;
}

int check_x(char *s) {
  int i = 0;
  while(s[i] != '0') i++;
  return i;
}

int cal() {
  char *s_right,*s_left,*s_up,*s_down;
  int k,tag;

  tag = que[head];
  char *s = tagtos(tag);
  int x = check_x(s);
  
  if((s_right = move_right(s, x)) != NULL) {
    if((k = create(s_right,flag[tag]+1))) return k;
    free(s_right);
  }
  if((s_left = move_left(s, x)) != NULL) {
     if((k = create(s_left,flag[tag]+1))) return k;
     free(s_left);
  }
  if ((s_up = move_up(s, x)) != NULL) {
    if((k = create(s_up,flag[tag]+1))) return k;
    free(s_up);
  }
  if((s_down = move_down(s, x)) != NULL) {
    if((k = create(s_down,flag[tag]+1))) return k;
    free(s_down);
  }
  free(s);
  head++;
  return 0;
}
  

int solve(char s0[]) {
  int k;
  if((k = create(s0,1))) return k;
  
  while(!(k = cal())) {
    if(head == rear) break;
  }
  return k;
}

int main()
{

  int i,d;
  char s[10];
  for(i = 0; i < 10; i++) factorial[i] = cal_factorial(i);
  flag = (char*)malloc(sizeof(char)*factorial[9]);
  memset(flag , 0, factorial[9]);
  que = (int*)malloc(sizeof(int)*factorial[9]);
  head = 0;
  rear = 0;
  for (i = 0; i < 9; i++) {
    scanf("%d", &d);
    s[i] = d+'0';
  }
  s[9] = '\0';
  printf("%d\n",solve(s)-1);
  
  return 0;
}
