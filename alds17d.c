#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int id;
  struct node *parent;
  struct node *left;
  struct node *right;
}Node;

void print_tree(Node *x,int t) {
  if(x->left != NULL) print_tree(x->left,1);
  if(x->right != NULL) print_tree(x->right,1);
  if(t == 1)printf("%d ", x->id);
  if(t == 0)printf("%d\n", x->id);
}

Node *make_tree(int *pre, int * in, int i, int j, int n, Node *p) {
  if(i >= n) return NULL;
  Node *p1 = (Node*)malloc(sizeof(Node));
  p1->id = pre[i];
  p1->parent = p;
  p1->left = NULL;
  p1->right = NULL;
  if(pre[i] != in[j]) {
    p1->left = make_tree(pre,in,i+1,j,n,p1);
  }else{
    Node *tmp = p1;
    while(1) {
      if(p == NULL) {
	break;
      }
      if(p->id == in[j+1]) {
	j++;
	tmp = p;
      }
      p = p->parent;
    }
    tmp->right = make_tree(pre,in,i+1,j+1,n,tmp);
  }
  return p1;
}

int main()
{
  int i,n,*preorder,*inorder;
  scanf("%d",&n);
  preorder = (int*)malloc(sizeof(int) * n);
  inorder = (int*)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    scanf("%d",preorder+i);
  }
  for (i = 0; i < n; i++) {
    scanf("%d",inorder+i);
  }
  Node *root = make_tree(preorder,inorder,0,0,n,NULL);
  print_tree(root,0);
  return 0;
}
