#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct node{
  int n,d,prev,n_branch,q;
  int branch[59],weight[59];
}Node;

Node nodes[61];//0 isnt used
Node* Q[61];//0 isnt used
int size;

void swap(int i, int j) {
  Node* tmp = Q[i];
  Q[i] = Q[j];
  Q[j] = tmp;
  int q;
  q = Q[i]->q;
  Q[i]->q = Q[j]->q;
  Q[j]->q = q;
}

void downheap(int n){
  if(2*n > size) return;
  if(2*n+1 > size) {
    if(Q[n]->d > Q[2*n]->d) {
      swap(n,2*n);
    }
  }
  else {
    int p,left,right;
    p = Q[n]->d;
    left = Q[2*n]->d;
    right = Q[2*n+1]->d;
    if(left < right) {
      if(p > left) {
        swap(n,2*n);
	downheap(2*n);
      }
    }
    else {
      if(p > right) {
        swap(n,2*n+1);
	downheap(2*n+1);
      }
    }
  }
  return;
}
void upheap(int n){
  if(n == 1) return;
  if(Q[n]->d < Q[n/2]->d) {
    swap(n,n/2);
    upheap(n/2);
  }
  return;
}

void delete(){
  swap(1,size);
  size--;
  downheap(1);
  return;
}

void update(int node_num, int new_d){
  nodes[node_num].d = new_d;
  upheap(nodes[node_num].q);
  downheap(nodes[node_num].q);
}

void print_heap(){
  int i,t;
  t = 2;
  for(i = 1; i <= size; i++) {
    printf("%d ", Q[i]->n);
    if(i+1 == t) {
      printf("\n");
      t*=2;
    }
    else if(i == size) printf("\n");
  }
}

void print_route(int n, int end, int start) {
  if(n == start) {
    if(start != 60) printf("%d",start);
    else printf("99");
  }
  else if(n != end) {
    print_route(nodes[n].prev,end,start);
    if(n != 60) printf("--%d", n);
    else printf("--99");
  }else{
    print_route(nodes[n].prev,end,start);
    if(end != 60) printf("--%d  ",end);
    else printf("--99  ");
  }
}

int main(int argc, char *argv[])
{
  int i,j,k;
  for(i = 1; i < 61; i++) {
    nodes[i].n = i;
    nodes[i].n_branch = 0;	  
  }
  
  char filename[30]; 
  if(argc == 1) return 1; 
  else strcpy(filename,argv[1]); 
  FILE* fp = fopen(filename, "r"); 
  
  while(fscanf(fp, "%d,%d,%d", &i, &j, &k) != EOF) { 
    if(i == 99) i = 60; 
    if(j == 99) j = 60; 
    nodes[i].branch[nodes[i].n_branch] = j; 
    nodes[j].branch[nodes[j].n_branch] = i;
    nodes[i].weight[nodes[i].n_branch] = k;
    nodes[j].weight[nodes[j].n_branch] = k;     
    nodes[i].n_branch++; 
    nodes[j].n_branch++; 
  }
    
  int start,end;
  while(scanf("%d %d", &start, &end) != EOF) {
    if(end == 99) end = 60;
    for(i = 1; i < 61; i++) {
      nodes[i].d = INT_MAX;
      nodes[i].prev = INT_MAX;
      nodes[i].q = i;
      Q[i] = &(nodes[i]);
    }
    size = 60;
    
    update(start, 0);
    while(size != 0) {
      Node* u = Q[1];
      delete();
      for(i = 0; i < u->n_branch; i++) {
	Node* v = &nodes[u->branch[i]];
	if(v->d > u->d+u->weight[i]){
	  v->prev = u->n;
	  update(v->n,u->d+u->weight[i]);
	}
      }
    }
    print_route(end,end,start);
    printf("(%d)\n",nodes[end].d);
  }
  
  
  return 0;
}
