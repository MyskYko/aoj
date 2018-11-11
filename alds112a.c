#include <stdio.h>
#include <stdlib.h>

typedef struct side{
  int a1;
  int a2;
  int weight;
  struct side *next;
}Side;

Side *add(Side *begin, int a1, int a2, int weight) {
  Side *p = (Side*)malloc(sizeof(Side));
  if(a1 < a2) {
    p->a1 = a1;
    p->a2 = a2;
  }
  else {
    p->a1 = a2;
    p->a2 = a1;
  }
  p->weight = weight;
  p->next = NULL;
  if(begin == NULL) return p;
  if(begin->weight < weight) {
    p->next = begin;
    return p;
  }
  Side *p2 = begin;
  while(p2->next != NULL && p2->next->weight > weight) p2 = p2->next;
  p->next = p2->next;
  p2->next = p;
  return begin;
}

void unite(int *affiliation, int *size, int p, int q) {
  int i,j;
  j = 0;
  for (i = 0; j < size[q]; i++) {
    if(affiliation[i] == q) {
      affiliation[i] = p;
      j++;
    }
  }
  size[p] +=  size[q];
}

int check(Side *begin, int m, int n, int x) {
  if(n-1 > m) return 1;
  int i,t,*affiliation,*size;
  Side *p;
  affiliation = (int*)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) affiliation[i] = -1;
  size = (int*)malloc(sizeof(int) * m);
  for (i = 0; i < m; i++) size[i] = 0;
  p = begin;
  i = 0;t = 0;
  int a1,a2;
  while(p != NULL) {
    if(i != x) {
      a1 = p->a1;
      a2 = p->a2;
      if(affiliation[a1] == -1 && affiliation[a2] == -1) {
      	affiliation[a1] = t;
      	affiliation[a2] = t;
      	size[t] += 2;
      	t++;
      }
      else if(affiliation[a1] != -1 && affiliation[a2] == -1) {
      	affiliation[a2] = affiliation[a1];
      	size[affiliation[a1]]++;
      }
      else if(affiliation[a1] == -1 && affiliation[a2] != -1) {
      	affiliation[a1] = affiliation[a2];
      	size[affiliation[a2]]++;
      }
      else if(affiliation[a1] != -1 && affiliation[a2] != -1 && affiliation[a1] != affiliation[a2]) {
      	 if(affiliation[a1] < affiliation[a2]) unite(affiliation,size,affiliation[a1],affiliation[a2]); 
      	 else unite(affiliation,size,affiliation[a2],affiliation[a1]); 
      }
    }
    p = p->next;
    i++;
  }
  for (i = 0; i < n; i++) {
    if(affiliation[i] != 0) return 1;
  }
  return 0;
}

Side *delete(Side *begin, int x) {
  Side *p = begin;
  if (x == 0) {
    p = p->next;
    free(begin);
    return p;
  }
  int i;
  for (i = 0; i < x-1; i++) {
    p = p->next;
  }
  Side *tmp = p->next;
  p->next = p->next->next;
  free(tmp);
  return begin;
}

Side *step(Side *begin, int *m, int n) {
  int x;
  x = 0;
  while(x < *m) {
    if(check(begin, *m, n, x) == 0) {
      begin = delete(begin, x);
      (*m)--;
    }
    else x++;
  }
  return begin;
}

long solve(int **a, int n) {
  int i,j,m;
  Side *begin = NULL;
  m = 0;
  for (i = 0; i < n; i++) {
    for (j = i+1; j < n; j++) {
      if(a[i][j] != -1) {
	begin = add(begin,i,j,a[i][j]);
	m++;
      }
    }
  }
  begin = step(begin,&m,n);
  long sum = 0;
  Side *p = begin;
  while(p != NULL) {
    sum += p->weight;
    p = p->next;
    free(begin);
    begin = p;
  }
  return sum;
}

int main()
{
  int i,j,n,**a;
  scanf("%d",&n);
  a = (int**)malloc(sizeof(int*) * n);
  for (i = 0; i < n; i++) {
    a[i] = (int*)malloc(sizeof(int) * n);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", a[i]+j);
    }
  }
  printf("%ld\n",solve(a,n));
  for (i = 0; i < n; i++) {
    free(a[i]);
  }
  free(a);

  return 0;
}

