#include <stdio.h>
#include <string.h>

typedef struct card {
  int value;
  char mark;
} card;

void swap_card(card *a, card *b) {
  int temp_value;
  char temp_mark;
  temp_value = a->value;
  temp_mark = a->mark;
  a->value = b->value;
  a->mark = b->mark;
  b->value = temp_value;
  b->mark = temp_mark;
}

void bubble_sort(int N, card *c) {
  int i,j;
  for(i = 0;i < N;i++)
    for(j = N-1; j > i; j--)
      if(c[j].value < c[j-1].value)
	swap_card(c+j-1, c+j);
}

void selection_sort(int N, card *a) {
  int i,j,mini;
  for(i = 0; i < N-1; i++) {
    mini = i;
    for(j = i+1; j < N; j++)
      if(a[mini].value > a[j].value)
	mini = j;
    if(i != mini) 
      swap_card(a+i, a+mini);
  }
}

int check_sort(int N, card *a, card *b, int p) {
  int i,j;
  i = 0; j = 0;
  while(1) {
    while(i < N && a[i].value != p) i++;
    while(j < N && b[j].value != p) j++;
    if(i == N || j == N) break;
    if(a[i].mark != b[j].mark) return 1;
    i++;j++;
  }

  return 0;
}

int main() {
  int N,i,j,t;
  char c;
  char stability[2][11] = {"Stable", "Not stable"};
  scanf("%d", &N);
  card a[N],a1[N],a2[N];
  memset(a, 0, sizeof(a));
  for(i = 0; i < N; i++) {
    scanf(" %c ", &c);
    a[i].mark = c;
    scanf("%d", &t);
    a[i].value = t;
  }

  memcpy(a1, a, sizeof(a));
  memcpy(a2, a, sizeof(a));

  bubble_sort(N, a1);
  selection_sort(N, a2);
  
  for(i = 0; i < N-1; i++) printf("%c%d ", a1[i].mark, a1[i].value);
  t = 0; j = 0;
  while(t == 0 && j < 9) {
    t += check_sort(N, a, a1, j);
    j++;
  }
  printf("%c%d\n%s\n", a1[i].mark, a1[i].value, stability[t]);
    for(i = 0; i < N-1; i++) printf("%c%d ", a2[i].mark, a2[i].value);
  t = 0; j = 0;
  while(t == 0 && j < 9) {
    t += check_sort(N, a, a2, j);
    j++;
  }
  printf("%c%d\n%s\n", a2[i].mark, a2[i].value, stability[t]); 
  
  return 0;
}
