#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element{
  long key;
  struct element *next;
  struct element *before;
}Element;

Element *insert(Element *begin, long key, Element **last) {
  Element *p;
  p = (Element*)malloc(sizeof(Element));
  p->key = key;
  p->next = begin;
  p->before = NULL;
  if(begin != NULL) {
    begin->before = p;
  }else{
    *last = p;
  }
  return p;
}

Element *delete(Element *begin, long key, Element **last) {
  Element *p = begin,*temp;
  while(p->key != key && p->next != NULL) p = p->next;
  if(p->next == NULL) {
    if(p->key != key) return begin;
    *last = p->before;
  }
  if(p->before != NULL) p->before->next = p->next;
  if(p->next != NULL) p->next->before = p->before;
  temp = begin;
  if(p == begin) temp = begin->next;
  free(p);

  return temp;
}

Element *deleteFirst(Element *begin, Element **last) {
  Element *p = begin->next;
  if(p != NULL) p->before = NULL;
  free(begin);
  if(p == NULL) *last = NULL;
  return p;
}

Element *deleteLast(Element *begin, Element **last) {
  Element *p = begin,*temp;
  p = (*last)->before;
  if(*last == begin) {
    temp = NULL;
  }else{
    temp = begin;
    (*last)->before->next = NULL;
  }
  free(*last);
  *last = p;

  return temp;
}

int main() {
  long i,n;
  scanf("%ld", &n);
  char command[12];
  long key;
  Element *begin;
  Element *last;
  for(i = 0; i < n; i++) {
    scanf(" %s", command);
    if(strcmp(command,"insert") == 0) {
      scanf("%ld", &key);
      begin = insert(begin, key, &last);
    }
    if(strcmp(command,"delete") == 0) {
      scanf("%ld", &key);
      begin = delete(begin, key, &last);
    }
    if(strcmp(command,"deleteFirst") == 0) begin = deleteFirst(begin, &last);
    if(strcmp(command,"deleteLast") == 0) begin = deleteLast(begin, &last);
  }

  Element *p = begin;
  while(p->next != NULL) {
    printf("%ld ", p->key);
    p = p->next;
  }
  printf("%ld\n", p->key);

  return 0;
}
