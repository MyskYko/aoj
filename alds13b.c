#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  long n,i,t,p,j,l;
  int q;
  scanf("%ld %d", &n, &q);

  long *time,*order,*finish,*half;
  char **name;
  time = (long*)malloc(sizeof(long)*n);
  finish = (long*)malloc(sizeof(long)*n);
  name = (char**)malloc(sizeof(char*)*n);
  order = (long*)malloc(sizeof(long)*n);
  for(i = 0; i < n; i++) {
    name[i] = (char*)malloc(sizeof(char)*11);
    scanf("%s %ld", name[i], time+i);
  }
  t = 0;
  p = 0;
  while(t < n/2) {
    for(i = 0; i < n; i++) {
      if(time[i] > 0) {
	time[i] -= q;
	p += q;
	if(time[i] <= 0) {
	  p += time[i];
	  finish[t] = p;
	  order[t] = i;
	  t++;
	}
      }
    }
  }
  j = 0;
  l = n - n/2;
  half = (long*)malloc(sizeof(long)*l);
  for(i = 0; i < n; i++) {
    if(time[i] > 0) {
      half[j] = i;
      j++;
    }
  }
  while(t < n) {
    for(i = 0; i < l; i++) {
      if(time[half[i]] > 0) {
	time[half[i]] -= q;
	p += q;
	if(time[half[i]] <= 0) {
	  p += time[half[i]];
	  finish[t] = p;
	  order[t] = half[i];
	  t++;
	}
      }
    }
  }
  

  for(i = 0; i < n; i++) {
    printf("%s %ld\n", name[order[i]], finish[i]);
  }
  
  return 0;
}
