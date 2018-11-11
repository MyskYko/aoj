#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int *children;
  int n_children;
  int depth;
  int parent;
}Node;

void depth_plus(Node *a, int x, int d) {
  int i;
  (a+x)->depth += d;
  for (i = 0; i < (a+x)->n_children; i++) {
    depth_plus(a,((a+x)->children)[i], d);
  }
}

int main()
{
  int i,j,n,id,n_children,child;
  Node *a;
  scanf("%d",&n);
  a = (Node*)malloc(sizeof(Node) * n);
  for (i = 0; i < n; i++) {
    (a+i)->children = NULL;
    (a+i)->depth = 0;
    (a+i)->parent = -1;
  }

  for (i = 0; i < n; i++) {
    scanf("%d %d",&id,&n_children);
    (a+id)->n_children = n_children;
    if(n_children != 0)
      (a+id)->children = (int*)malloc(sizeof(int) * n_children);
    for(j = 0; j < n_children; j++) {
      scanf("%d",&child);
      ((a+id)->children)[j] = child;
      depth_plus(a,child,(a+id)->depth+1);
      (a+child)->parent = id;
    }
  }

  for (i = 0; i < n; i++) {
    printf("node %d: parent = %d, depth = %d, ",i,(a+i)->parent,(a+i)->depth);
    if((a+i)->parent == -1) {
      printf("root, [");
    }else if((a+i)->n_children > 0){
      printf("internal node, [");
    }else{
      printf("leaf, [");
    }
    for (j = 0; j < (a+i)->n_children; j++) {
      printf("%d", ((a+i)->children)[j]);
      if(j != (a+i)->n_children-1) printf(", ");
    }
    printf("]\n");
  }


  
  return 0;
}
