#include <stdio.h>
#include <stdlib.h>

typedef struct matrix{
  int row;
  int column;
  struct matrix *next;
  struct matrix *back; 
}Matrix;

Matrix *push_back(Matrix *begin, int row, int column) {
  Matrix *p = (Matrix*)malloc(sizeof(Matrix));
  p->row = row;
  p->column = column;
  p->next = NULL;
  p->back = NULL;
  if(begin == NULL) return p;
  Matrix *p2 = begin;
  while(p2->next != NULL) p2 = p2->next;
  p2->next = p;
  p->back = p2;
  return begin;
}

Matrix *product_count(Matrix *x, int type, int *count) {
  Matrix *a,*b;
  if(type == 0) {
    a = x->back;
    b = x;
  }
  else {
    a = x;
    b = a->next;
  }
  *count = 0;
  if(a == NULL || b == NULL) return x;
  *count += a->row * a->column * b->column;
  Matrix *c = (Matrix*)malloc(sizeof(Matrix));
  c->row = a->row;
  c->column = b->column;
  c->next = b->next;
  c->back = a->back;
  if(a->back != NULL) a->back->next = c;
  if(b->next != NULL) b->next->back = c;
  free(a);
  free(b);
  return c;
}

int main()
{
  int i,n,r,c;
  Matrix *begin = NULL;
  scanf("%d",&n);
  for (i = 0; i < n; i++) {
    scanf("%d %d",&r,&c);
    begin = push_back(begin,r,c);
  }
  Matrix *min = begin, *p = begin;
  while (p->next != NULL) {
    if(min->column > p->column) min = p;
    p = p->next;
  }
  long sum = 0;
  int count;
  if(min->column <= begin->row) {
    begin = NULL;
    while(1) {
      min = product_count(min,0,&count);
      if(count != 0) sum += count;
      else break;
    }
    if(min->next != NULL) {
      min = min->next;
      while(1) {
	min = product_count(min,1,&count);
	if(count != 0) sum += count;
	else break;
      }
    }
  }
  else{
    min = begin;
    begin = NULL;
    while(1) {
      min = product_count(min,1,&count);
      if(count != 0) sum += count;
      else break;
    }
  }

  printf("%ld\n",sum);
  
  return 0;
}
