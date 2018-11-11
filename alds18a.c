#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
  long key;
  struct node *left;
  struct node *right;
  struct node *p;
}Node;

void print_tree(Node *x,int order) {
  if (order == 0) {
    printf(" %ld", x->key);    
  }
  if(x->left != NULL) print_tree(x->left,order);
  if (order == 1) {
    printf(" %ld", x->key);    
  }
  if(x->right != NULL) print_tree(x->right,order);
  if (order == 2) {
    printf(" %ld", x->key);    
  }
}

Node *insert(Node *root, long key) {
  Node *z = (Node*)malloc(sizeof(Node));
  z->key = key;
  z->p = NULL;
  z->left = NULL;
  z->right = NULL;
  Node *x,*y;
  y = NULL;
  x = root;
  while(x != NULL) {
    y = x;
    if(z->key < x->key) x = x->left;
    else x = x->right;
  }
  z->p = y;
  if(y  == NULL) return z;
  else if(z->key < y->key) y->left = z;
  else y->right = z;
  return root;
}

int main()
{
  long i,N,key;
  char command[7];
  Node *root = NULL;
  scanf("%ld",&N);
  for (i = 0; i < N; i++) {
    scanf("%s",command);
    if(strcmp(command,"insert") == 0) {
      scanf("%ld",&key);
      root = insert(root,key);
    }
    if(strcmp(command,"print") == 0) {
      print_tree(root,1);
      printf("\n");
      print_tree(root,0);
      printf("\n");
    }
  }

  return 0;
}
