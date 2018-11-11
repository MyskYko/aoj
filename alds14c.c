#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define HASHSIZE 5000

typedef struct word{
  char *str;
  struct word *next;
}Word;

Word *hashtable[HASHSIZE] = {0};

int hash(char *key) {
  unsigned int hash = 0;
  int length = strlen(key);
  int i;
  for(i = 0; i < length; i++) hash += key[i] * pow(7,i);
  
  return hash%HASHSIZE;
}

void put_word(char *str) {
  Word *a;
  int l = strlen(str);
  a = (Word*)malloc(sizeof(Word));
  a->str = (char*)malloc(sizeof(char)*(l+1));
  strcpy(a->str,str);
  int h = hash(a->str);
  a->next = hashtable[h];
  hashtable[h] = a;
}


int main() {
  long n,i;
  scanf("%ld", &n);
  
  for(i = 0; i < n; i++) {
    char command[7];
    scanf("%s", command);
    if(strcmp(command, "insert") == 0) {
      char str1[13];
      scanf("%s", str1);
      put_word(str1);
    }
    if(strcmp(command, "find") == 0) {
      char str2[13];
      scanf("%s", str2);
      Word *a = hashtable[hash(str2)];
      while(a != NULL){
	if(strcmp(a->str,str2) == 0) break;
	a = a->next;
      }
      if(a != NULL) {
	printf("yes\n");
      }else{
	printf("no\n");
      }      
    }
  }

  return 0;
}
