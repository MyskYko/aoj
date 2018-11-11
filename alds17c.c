#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int id;
  struct node *left;
  struct node *right;
  int parent;
  int n_child;
}Node;

void print_tree(Node *x,int order) {
  if (order == 0) {
    printf(" %d", x->id);    
  }
  if(x->left != NULL) print_tree(x->left,order);
  if (order == 1) {
    printf(" %d", x->id);    
  }
  if(x->right != NULL) print_tree(x->right,order);
  if (order == 2) {
    printf(" %d", x->id);    
  }
}

int main()
{
  int i,n,id,left,right;
  Node *T;
  scanf("%d",&n);
  T = (Node*)malloc(sizeof(Node) * n);
  for (i = 0; i < n; i++) {
    T[i].id = i;
    T[i].left = NULL;
    T[i].right = NULL;
    T[i].parent = 0;
    T[i].n_child = 0;
  }

  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &id, &left,&right);
    if(left != -1) {
      T[id].left = T+left;
      T[left].parent++;
      T[id].n_child++;;
    }
    if(right != -1) {
      T[id].right = T+right;
      T[right].parent++;
      T[id].n_child++;
    }
  }

  for (i = 0; i < n; i++) {
    if(T[i].parent == 0) id = i;
  }


  printf("Preorder\n");
  print_tree(T+id,0);
  printf("\nInorder\n");
  print_tree(T+id,1);
  printf("\nPostorder\n");
  print_tree(T+id,2);
  printf("\n");

  return 0;
}
