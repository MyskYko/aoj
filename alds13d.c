#include <stdio.h>
#include <string.h>

int main() {
  int height,length,i,j,t,max,depth,left,right,last_height,sum;
  char section[20001],reverse[20001];
  int L[10000] = {0},reverse_L[10000] = {0};

  scanf("%s", section);
  length = strlen(section);
  for(i = 0; i < length; i++) reverse[i] = section[length-i-1];
  reverse[i] = '\0';
  
  max = 0;height = 0;t = 0;
  for(i = 0; i < length; i++) {
    if(section[i] =='\\') height--;
    if(section[i] == '/') {
      height++;
      if(max == height) t++;
      if(max < height) {
	max = height;
	t = 0;
      }
    }
  }
  last_height = height;

  
  height = 0;depth = 0;i = 0;j = 0;
  while(height < max) {
    if(section[i] =='\\') {
      height--;
      depth++;
    }
    if(section[i] == '/') {
      height++;
      if(depth > 0) depth--;
      if(depth == 0 && L[j] > 0) j++;
    }
    L[j] += depth;
    i++;
  }
  
  while(t > 0) {
    if(section[i] =='\\') {
      height--;
      depth++;
    }
    if(section[i] == '/') {
      height++;
      if(depth > 0) depth--;
      if(depth == 0 && L[j] > 0) {
	j++;
	t--;
      }
    }
    L[j] += depth;
    i++;
  }
  left = j;
  
  height = last_height;depth = 0;i = 0;j = 0;
  while(height < max) {
    if(reverse[i] =='/') {
      height--;
      depth++;
    }
    if(reverse[i] == '\\') {
      height++;
      if(depth > 0) depth--;
      if(depth == 0 && reverse_L[j] > 0) j++;
    }
    reverse_L[j] += depth;
    i++;
  }
  right = j;

  for(i = 0; i < right; i++) L[left+i] = reverse_L[right-i-1];
  sum = 0;
  for(i = 0; i < left+right; i++) sum += L[i];

  printf("%d\n", sum);
  printf("%d", left+right);
  if(left+right != 0) printf(" ");
  for(i = 0; i < left+right-1; i++) printf("%d ", L[i]);
  if(left+right != 0) printf("%d", L[i]);
  printf("\n");

  return 0;
}
