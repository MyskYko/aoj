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

int main() {
  int i,c,num[7];
  struct dice *dice1;
  for(i = 1;i <= 6;i++) {
    scanf("%d", num+i);
  }
  dice1 = make_dice(num);
  while((c = getchar()) != EOF) {
    switch (c) {
    case 'S':
      turnS(dice1);
      break;
    case 'W':
      turnW(dice1);
      break;
    case 'N':
      turnN(dice1);
      break;
    case 'E':
      turnE(dice1);
      break;
    default:
      break;
    }
  }
  printf("%d\n",dice1->label[1]);

  free(dice1);
  return 0;
}
