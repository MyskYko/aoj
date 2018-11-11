#include <stdio.h>
#include <stdlib.h>

struct dice {
  int label[7];
};

struct dice *make_dice(int *num) {
  int i;
  struct dice *dice1;
  dice1 = (struct dice *)malloc(sizeof(struct dice));
  for(i = 1;i <= 6;i++) {
    dice1->label[i] = num[i];
  }
  return dice1;
}

void turnS(struct dice *a) {
  int temp;
  temp = a->label[1];
  a->label[1] = a->label[5];
  a->label[5] = a->label[6];
  a->label[6] = a->label[2];
  a->label[2] = temp;
}

void turnW(struct dice *a) {
  int temp;
  temp = a->label[1];
  a->label[1] = a->label[3];
  a->label[3] = a->label[6];
  a->label[6] = a->label[4];
  a->label[4] = temp;
}

void turnN(struct dice *a) {
  int temp;
  temp = a->label[1];
  a->label[1] = a->label[2];
  a->label[2] = a->label[6];
  a->label[6] = a->label[5];
  a->label[5] = temp;
}

void turnE(struct dice *a) {
  int temp;
  temp = a->label[1];
  a->label[1] = a->label[4];
  a->label[4] = a->label[6];
  a->label[6] = a->label[3];
  a->label[3] = temp;
}

void spin(struct dice *a) {
  turnS(a);
  turnE(a);
  turnN(a);
}

int cmp_dice(struct dice *a, struct dice *b) {
  int i;
  for(i = 1;i <= 6;i++) {
    if(a->label[i] != b->label[i]) return 1;
  }
  return 0;
}

int cmp_dice2(struct dice *dice1, struct dice *dice2) {
  int i,j;
  
  for(i = 0;i < 4;i++) {
    for(j = 0;j < 4;j++) {
      if(cmp_dice(dice1, dice2) == 0) break;
      spin(dice1);
    }
    if(cmp_dice(dice1, dice2) == 0) break;
    turnW(dice1);
  }
  for(i = 0;i < 4;i++) {
    for(j = 0;j < 4;j++) {
      if(cmp_dice(dice1, dice2) == 0) break;
      spin(dice1);
    }
    if(cmp_dice(dice1, dice2) == 0) break;
    turnS(dice1);
  }
  if(cmp_dice(dice1, dice2) == 0) {
    return 0;
  }else{
    return 1;
  }
}

int main() {
  int i,j,n,t,num[7];
  struct dice **dice;

  scanf("%d", &n);
  dice = (struct dice **)malloc(sizeof(struct dice *)*n);
  for(i = 0;i < n;i++) {
    for(j = 1;j <= 6;j++) {
      scanf("%d", num+j);
    }
    dice[i] = make_dice(num);
  }
  t = 0;
  for(i = 0;i < n-1;i++) {
    for(j = i+1; j < n;j++) {
      t += 1 - cmp_dice2(dice[i], dice[j]);
    }
  }

  if(t == 0) {
    printf("Yes\n");
  }else{
    printf("No\n");
  }

  for(i = 0;i < n;i++) {
    free(dice[i]);
  }
  free(dice);
  return 0;
}
