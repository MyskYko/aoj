#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char value;
  struct node *left;
  struct node *right;
};

void parse(struct node *n) {
  if(n->value >= '0' && n->value <= '9') {
    printf("%c",n->value);
  }else{
    switch(n->value) {
    case '+':
      printf("Plus[");
      break;
    case '-':
      printf("Subtract[");
      break;
    case '*':
      printf("Times[");
      break;
    case '/':
      printf("Devide[");
      break;
    default:
      break;
    }
    parse(n->left);
    printf(",");
    parse(n->right);
    printf("]");
  }
}

double cal(struct node *n) {
  switch(n->value) {
  case '+':
    return cal(n->left) + cal(n->right);
    break;
  case '-':
    return cal(n->left) - cal(n->right);
    break;
  case '*':
    return cal(n->left) * cal(n->right);
    break;
  case '/':
    return (double)cal(n->left) / cal(n->right);
    break;
  default:
    return n->value - '0';
  }
}

struct node *create_node(int p, char *s) {
  struct node *a;
  a = (struct node*)malloc(sizeof(struct node));
  char *v;
  if(p == 0){
    v = strtok(s,"[]");
  }else{
    v = strtok(NULL, "[]");
  }
  //v no hanbetu
  if(a->value < '0' || a->value > '9') {
    a->left = create_node(1,s);
    a->right = create_node(1,s);
  }else{
    a->left = NULL;
    a->right = NULL;
  }
  return a;
}

int main() {
  char *str = "+/9*84-*84+73";// 22.281250
  struct node *root = create_node(0, str);
  parse(root);
  printf("\n");
  return 0;
}
