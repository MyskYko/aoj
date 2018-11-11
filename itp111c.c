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

int main() {
  int i,j,num[7];
  struct dice *dice1,*dice2;
  for(i = 1;i <= 6;i++) {
    scanf("%d", num+i);
  }
  dice1 = make_dice(num);

  for(i = 1;i <= 6;i++) {
    scanf("%d", num+i);
  }
  dice2 = make_dice(num);
  
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
    printf("Yes\n");
  }else{
    printf("No\n");
  }

  free(dice1);
  free(dice2);
  return 0;
}
