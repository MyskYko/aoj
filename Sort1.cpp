#include <iostream>
using namespace std;

void swap(int *num, int a, int b) {
  int tmp;
  tmp = num[a];
  num[a] = num[b];
  num[b] = tmp;
}


void sort(int *num, int n) {
  if(n == 1) {
    return;
  }
  int mid = n/2;
  int a[mid],b[n-mid];
  for (int i = 0; i < mid; i++) {
    a[i] = num[i];
  }
  for (int i = 0; i < n-mid; i++) {
    b[i] = num[mid+i];
  }
  sort(a,mid);
  sort(b,n-mid);
  int p=0,q=0;
  while(p < mid || q < n-mid) {
    if(p == mid) {
      num[p+q] = b[q];
      q++;
    }
    else if(q == n-mid) {
      num[p+q] = a[p];
      p++;
    }
    else if(a[p] > b[q]) {
      num[p+q] = b[q];
      q++;
    }
    else{
      num[p+q] = a[p];
      p++;
    }
  }
  
}

int main()
{
  int n;
  cin >> n;
  int num[n];
  for (int i = 0; i < n; i++) cin >> num[i];
  sort(num,n);
  for (int i = 0; i < n; i++) {
    cout << num[i];
    if(i != n-1) cout << " ";
    else cout << endl;
  }
  return 0;
}
