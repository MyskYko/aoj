#include <cstdio>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define llong long long

int main() {
  int n;
  scanf("%d ",&n);
  char a[102],b[102];
  REP(i,n) {
    fgets(a,101,stdin);
    fgets(b,101,stdin);
    int al = strlen(a);
    int bl = strlen(b);
    if(a[al-1] == '\n') a[--al] = '\0';
    if(b[bl-1] == '\n') b[--bl] = '\0';
    char answer[103];
    REP(j,102) {
      answer[j] = '0';
    }
    answer[102] = '\0';
    REPR(j,101) {
      int anow,bnow;
      if(--al >= 0) anow = a[al]-'0';
      else anow = 0;
      if(--bl >= 0) bnow = b[bl]-'0';
      else bnow = 0;
      int t = (answer[j]-'0') + anow + bnow;
      answer[j] = t%10 + '0';
      if(j != 0) answer[j-1] += t/10;
    }
    int k = 0;
    while(k < 101 && answer[k] == '0'){
      k++;
    }
    if(k > 21)printf("%s\n",answer+k);
    else printf("overflow\n");
  }
  return 0;
}
