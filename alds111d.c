#include <stdio.h>
#include <stdlib.h>

void unite(long *affiliation, long *group, long p, long q) {
  long i,j;
  j = 0;
  for (i = 0; j < group[q]; i++) {
    if(affiliation[i] == q) {
      affiliation[i] = p;
      j++;
    }
  }
  group[p] += group[q];
}

int main()
{
  long n,m,i,s,t,p,q;
  long *affiliation,*group;
  scanf("%ld %ld",&n,&m);
  affiliation = (long*)malloc(sizeof(long) * n);
  for (i = 0; i < n; i++) affiliation[i] = -1;
  group = (long*)malloc(sizeof(long) * m);
  for (i = 0; i < m; i++) group[i] = 0;
  p = 0;
  for (i = 0; i < m; i++) {
    scanf("%ld %ld", &s, &t);
    if(affiliation[s] == -1 && affiliation[t] == -1) {
      affiliation[s] = p;
      affiliation[t] = p;
      group[p] += 2;
      p++;
    }
    else if(affiliation[s] != -1 && affiliation[t] == -1) {
      affiliation[t] = affiliation[s];
      group[affiliation[s]]++;
    }
    else if(affiliation[s] == -1 && affiliation[t] != -1) {
      affiliation[s] = affiliation[t];
      group[affiliation[t]]++;
    }
    else if(affiliation[s] != affiliation[t]){
      (affiliation[s] < affiliation[t]) ? unite(affiliation,group,affiliation[s],affiliation[t]):unite(affiliation,group,affiliation[t],affiliation[s]);
    }
  }
  scanf("%ld",&q);
  for (i = 0; i < q; i++) {
    scanf("%ld %ld", &s, &t);
    if(affiliation[s] == affiliation[t] && affiliation[s] != -1) printf("yes\n");
    else printf("no\n");
  }
  free(affiliation);
  free(group);
  
  return 0;
}
