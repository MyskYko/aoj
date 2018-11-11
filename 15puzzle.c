#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int *data;
  int depth;
  struct node *next;
}Node;

Node *create_Node(int *data, int depth) {
  Node *p = (Node*)malloc(sizeof(Node));
  p->data = data;
  p->depth = depth;
  p->next = NULL;
  return p;
}

Node *pop(Node *begin) {
  Node *tmp = begin->next;
  free(begin->data);
  free(begin);
  return tmp;
}

Node *push_back(Node *begin, Node *p) {
  p->next = NULL;
  
  if(begin == NULL) {
    return p;
  }
  else {
  Node *tmp = begin;
  while(tmp->next != NULL) {tmp = tmp->next;}
  tmp->next = p;
  return begin;
  }
  return NULL;
}

//nomatch = 0, match = 1;
int compare_data(int *data1, int *data2) {
  int i;
  for(i = 0; i < 16; i++) {
    if(data1[i] != data2[i]) {return 0;}
  }
  return 1;
}

//not found = -1, found = depth
int search_for(int *data, Node *begin) {
  Node *tmp = begin;
  while(tmp != NULL) {
    if(compare_data(data, tmp->data)) {return tmp->depth;}
    tmp = tmp->next;
  }
  return -1;
}

void add_Node(Node* n){
  int i;
  int addr;
  for(i = 0; i < 16; i++) {
    if(n->data[i] == 0) {
      addr = i;
      break;
    }
  }
  
  //moveup
  if(addr > 3) {
    int *up_data = (int*)malloc(16*sizeof(int));
    for(i = 0; i < 16; i++) {
      up_data[i] = n->data[i];
    }
    up_data[addr-4] = 0;
    up_data[addr] = n->data[addr-4];
    Node *up = create_Node(up_data, n->depth+1);
    push_back(n,up);
  }
  //movedown
  if(addr < 12) {
    int *down_data = (int*)malloc(sizeof(int)*16);
    for(i = 0; i < 16; i++) {
      down_data[i] = n->data[i];
    }
    down_data[addr+4] = 0;
    down_data[addr] = n->data[addr+4];
    Node *down = create_Node(down_data, n->depth+1);
    push_back(n,down);
  }
  //moveleft
  if(addr%4 != 0) {
    int *left_data = (int*)malloc(sizeof(int)*16);
    for(i = 0; i < 16; i++) {
      left_data[i] = n->data[i];
    }
    left_data[addr-1] = 0;
    left_data[addr] = n->data[addr-1];
    Node *left = create_Node(left_data, n->depth+1);
    push_back(n,left);
  }
  //moveright
  if(addr%4 != 3) {
    int *right_data = (int*)malloc(sizeof(int)*16);
    for(i = 0; i < 16; i++) {
      right_data[i] = n->data[i];
    }
    right_data[addr+1] = 0;
    right_data[addr] = n->data[addr+1];
    Node *right = create_Node(right_data, n->depth+1);
    push_back(n,right);
  }
  
}

Node* create_list() {
  int i;
  int *first = (int*)malloc(16*sizeof(int));
  for(i = 0; i < 15; i++) {first[i] = i+1;}
  first[15] = 0;
  Node *begin = create_Node(first, 0);
  Node *finished = NULL;
  
  while(begin != NULL) {
    if(search_for(begin->data, finished) >= 0) {
      begin = pop(begin);
    }
    else if(begin->depth >= 11){
      Node *tmp = begin;
      begin = begin->next;
      finished = push_back(finished, tmp);
    }
    else{
      add_Node(begin);
      Node *tmp = begin;
      begin = begin->next;
      finished = push_back(finished, tmp);
    }
  }
  
  return finished;
}

int main(int argc, char **argv) {
  Node *begin = create_list();
  int i;
  int *data = (int*)malloc(sizeof(int)*16);
  printf("please type the data\n");
  for(i = 0; i < 16; i++) {
    scanf("%d", data+i);
  }
  int depth = search_for(data, begin);
  printf("%d\n", depth);
  return 0;
}
