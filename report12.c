#include <stdio.h>
#include <stdlib.h>

struct node {
  char value;
  struct node *left;
  struct node *right;
};

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

struct node *create_node(int *pos, char *s) {
  struct node *a;
  a = (struct node*)malloc(sizeof(struct node));
  a->value = s[*pos];
  (*pos)++;
  if(a->value < '0' || a->value > '9') {
    a->left = create_node(pos,s);
    a->right = create_node(pos,s);
  }else{
    a->left = NULL;
    a->right = NULL;
  }
  return a;
}

int main() {
  char *str = "+-8*2+-8/27-*5*3+-8*2+-8/22-*2*315//2/9755/*2/945";// 234.138095
  int p = 0;
  struct node *root = create_node(&p, str);
  printf("%lf\n", cal(root));
  return 0;
}
