#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 50


typedef struct node {
  char str[MAX_LENGTH];
  int count[2];
  struct node *left;
  struct node *right;
} Node;

Node *root = NULL;

void delete(Node *p) {
  p->count[0] = 0;
  p->count[1] = 0;
  
}

Node *max_node(Node *p,int flag){
  if(p == NULL) return NULL;
  int ln,rn,n;
  Node *l = max_node(p->left, flag);
  Node *r = max_node(p->right, flag);
  if(l != NULL) ln = l->count[flag];
  else ln = 0;
  if(r != NULL) rn = r->count[flag];
  else rn = 0;
  if(flag == 0) {
    if(p->count[1] != 0) n = 0;
    else n = p->count[0];
  }else {
    if(p->count[0] != 0) n = 0;
    else n = p->count[1];
  }
  int max = n;
  if(max < ln) {
    max = ln;
    p = l;
  }
  if(max < rn) {
    max = rn;
    p = r;
  }

  if(max == 0) return NULL;
  else return p;
  
}

void print_node(Node *p){
  if(p == NULL) return ;
  printf("%s %d %d\n", p->str, p->count[0], p->count[1]);
  print_node(p->left);
  print_node(p->right);
}

void add_node(int flag, char *str)
{
  Node *p  = root;
  Node *parent = NULL;
  while(p != NULL) {
    parent = p;
    if(strcmp(p->str, str) > 0) p = p->right;
    else if(strcmp(p->str, str) < 0) p = p->left;
    else if(strcmp(p->str, str) == 0) {
      p->count[flag]++;
      break;
    }
  }
if(p == NULL) {
    p = (Node*)malloc(sizeof(Node));
    strcpy(p->str,str);
    p->count[0] = 0;
    p->count[1] = 0;
    p->count[flag] = 1;
    p->left = NULL;
    p->right = NULL;
    if(parent == NULL) root = p;
    else if(strcmp(parent->str, str) > 0) parent->right = p;
    else if(strcmp(parent->str, str) < 0) parent->left = p;
  }
}


void input()
{
  int t,k;
  char c,str[MAX_LENGTH];
  t = 0;
  k = 0;
  while((c = getchar()) != EOF)  {
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-' || c == '\'') {
      if(t > 0 || (c != '-' && c != '\'')) {
	if(c >= 'A' && c <= 'Z') c += -'A' + 'a';
	str[t] = c;
        t++;
        if(t > MAX_LENGTH) printf("bigg!\n");
      }
    }
    else if(t > 0){ 
      while(str[t-1] == '-' || str[t-1] == '\'') t--; 
      str[t] = '\0';
      add_node(k,str); 
      t = 0;
    }
    if(c == '@') k++;
  }
}

int main(){
  input();
  //print_node(root);
  Node *p;
  int i;
  printf("zenhan ni ari kohan ni nai\n");
  for(i = 0; i < 5; i++) {
    p = max_node(root, 0);
    printf("%s %d\n", p->str, p->count[0]);
    delete(p);
  }
  printf("\nkohan ni ari zenhan ni nai\n");
  for(i = 0; i < 5; i++) {
    p = max_node(root, 1);
    printf("%s %d\n", p->str, p->count[1]);
    delete(p);
  }
  return 0;
}
