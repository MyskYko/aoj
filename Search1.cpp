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

int search(int *num, int key, int l, int r) {
  if(l > r) return 0;
  int mid = (l+r)/2;
  if (num[mid] == key) return 1;
  else if(num[mid] > key) return search(num, key, l, mid-1);
  else if(num[mid] < key) return search(num, key, mid+1, r);
  return 0;
  
}

int main()
{
  int n,q,c;
  cin >> n;
  int num[n];
  for (int i = 0; i < n; i++) cin >> num[i];
  sort(num,n);
  cin >> q;
  c = 0;
  for (int i = 0; i < q; i++) {
    int key;
    cin >> key;
    c += search(num, key, 0, n-1);
  }
  cout << c << endl;
  return 0;
}
