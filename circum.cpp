#include <cstdio>
#include <complex>
#include <vector>
#include <cmath>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)

typedef complex<double> P;
typedef vector<P> VP;
const double EPF = 1e-9;

#define X real()
#define Y imag()
#define EQ(x,y) (abs(x-y) < EPF)

double dot(P a, P b) {
  return (conj(a)*b).X;
}
double cross(P a, P b) {
  return (conj(a)*b).Y;
}
double distPP(P a, P b) {
  return sqrt(dot(a-b,a-b));
}
P crosspoint(P a, P b, P c, P d) {//ac & bd
  double d1 = cross(d-b,b-a);
  double d2 = cross(d-b,c-a);
  if(EQ(d1,0) & EQ(d2,0)) return a;
  if(EQ(d2,0)) return a;
  return a + (c-a)*d1/d2;
}
P normal_vector(P a) {
  P b(-a.Y, a.X);
  return b;
}

int main() {
  int n;
  scanf("%d", &n);
  REP(j, n) {
    VP a;
    REP(i, 3) {
      double x,y;
      scanf("%lf %lf", &x, &y);
      a.push_back(P(x,y));
    }
    P M = (a[0]+a[1])/(P)2;
    P N = (a[1]+a[2])/(P)2;
    P M_v = normal_vector(a[0]-a[1]);
    P N_v = normal_vector(a[1]-a[2]);

    P o = crosspoint(M, N, M+M_v, N+N_v);
    
    printf("%.3lf %.3lf %.3lf\n", o.X, o.Y, distPP(o,a[0]));
    a.clear();
  }
  return 0;
}
