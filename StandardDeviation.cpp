#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
 int main()
 {
   int n;
   while(cin >> n, n != 0) {
     int sum;
     double m,a;
     int point[n];
     sum = 0;
     for(int i = 0; i < n; i++) {
       cin >> point[i];
       sum += point[i];
     }
     m = sum*1.0/n;
     a = 0;
     for(int i = 0; i < n; i++) {
       a += (point[i] - m)*(point[i] - m);
     }
     a = sqrt(a/n);
     cout << fixed << setprecision(4) << a << endl;
   }
   return 0;
 }
