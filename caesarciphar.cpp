#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define llong long long

int main() {
  char *a = (char*)malloc(sizeof(char)*82);
  size_t l = 0;
  while (getline(&a, &l, stdin) != EOF) {
    while(1) {
      int q = 0;//-1..out, 0..space, 1..t, 2..th, 3..the, 4...thi, 5..this, 6..tha, 7..that, 8..ok
      REP(j , (int)l-1) {
	if(a[j] == 'z') a[j] = 'a';
	else if(a[j] >= 'a' && a[j] < 'z') a[j]++;
      }
      REP(j , (int)l-1) {
	switch(q){
	case -1:
	  if(a[j] == ' ') q = 0;
	  break;
	case 0:
	  if(a[j] == 't') q = 1;
	  else q = -1;
	  break;
	case 1:
	  if(a[j] == 'h') q = 2;
	  else q = -1;
	  break;
	case 2:
	  if(a[j] == 'e') q = 3;
	  else if(a[j] == 'i') q = 4;
	  else if(a[j] == 'a') q = 6;
	  else q = -1;
	  break;
	case 3:
	  if(a[j] > 'z' || a[j] < 'a') q = 8;
	  else q = -1;
	  break;
	case 4:
	  if(a[j] == 's') q = 5;
	  else q = -1;
	  break;
	case 5:
	  if(a[j] > 'z' || a[j] < 'a') q = 8;
	  else q = -1;
	  break;
	case 6:
	  if(a[j] == 't') q = 7;
	  else q = -1;
	  break;
	case 7:
	  if(a[j] > 'z' || a[j] < 'a') q = 8;
	  else q = -1;
	  break;
	}
      }
      if(q == 8) break;
    }
    printf("%s",a);
    /*    REP(i , (int)l-1) {
      printf("%c",a[i]);
    }*/
  }
  return 0;
}
