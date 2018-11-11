#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int *children;
  int n_children;
  int depth;
  int height;
  int sibling;
  int parent;
}Node;

void depth_plus(Node *a, int x, int d) {
  int i;
  (a+x)->depth += d;
  for (i = 0; i < (a+x)->n_children; i++) {
    depth_plus(a,((a+x)->children)[i], d);
  }
}

int height_plus(Node *a, int x) {
  int i,v2;
  v2 = 0;
  for (i = 0; i < (a+x)->n_children; i++) {
    int v1 = height_plus(a,((a+x)->children)[i]);
    if(v1 > v2) v2 = v1;
  }
  (a+x)->height = v2;
  return v2+1;
}

int main()
{
  int i,j,n,id,n_children,child1,child2;
  Node *a;
  scanf("%d",&n);
  a = (Node*)malloc(sizeof(Node) * n);
  for (i = 0; i < n; i++) {
    (a+i)->children = NULL;
    (a+i)->depth = 0;
    (a+i)->height = 0;
    (a+i)->parent = -1;
    (a+i)->sibling = -1;
    (a+i)->n_children = 0;
  }
  for (i = 0; i < n; i++) {
    scanf("%d %d %d",&id,&child1,&child2);
    n_children = 0;
    if(child1 >= 0 || child2 >= 0) n_children = 1;
    if(child1 >= 0 && child2 >= 0) n_children = 2;
    (a+id)->n_children = n_children;
    if(n_children != 0)
      (a+id)->children = (int*)malloc(sizeof(int) * n_children);
    if(n_children == 2) {
      (a+child1)->sibling = child2;
      (a+child2)->sibling = child1;
    }
    j=0;
    if(child1 != -1) {
      ((a+id)->children)[j] = child1;
      depth_plus(a,child1,(a+id)->depth+1);
      (a+child1)->parent = id;
      j++;
    }
    if(child2 != -1) {
      ((a+id)->children)[j] = child2;
      depth_plus(a,child2,(a+id)->depth+1);
      (a+child2)->parent = id;
    } 
  }
  for (i = 0; i < n; i++) {
    if((a+i)->parent == -1) id = i;
  }
  id = height_plus(a,id);
  
  for (i = 0; i < n; i++) {
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,(a+i)->parent,(a+i)->sibling,(a+i)->n_children,(a+i)->depth,(a+i)->height);
    if((a+i)->parent == -1) {
      printf("root\n");
    }else if((a+i)->n_children > 0){
      printf("internal node\n");
    }else{
      printf("leaf\n");
    }
  }
  
  return 0;
}
