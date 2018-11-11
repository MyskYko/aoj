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
const double EPF = 1e-2;

#define X real()
#define Y imag()
#define EQ(x,y) (abs(x-y) < EPF)

double dot(P a, P b) {
  return (conj(a)*b).X;
}
double cross(P a, P b) {
  return (conj(a)*b).Y;
}
int isparallel(P a, P b, P c, P d) {//ab,cd
  return EQ(cross(a-b, c-d),0);
}
double distPP(P a, P b) {
  return sqrt(dot(a-b,a-b));
}
int relationCC(P c1, double r1, P c2, double r2) {//0..not overlap, 1..intersect, 2..2isin1, -2..1isin2
  double d = distPP(c1,c2);
  if(d > r1+r2) return 0;
  else if(r1 > d+r2) return 2;
  else if(r2 > d+r1) return -2;
  else return 1;
}
P intersection(P a, P b, P c, P d) {//ac , bd
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
P polar(double r, double theta) {
  P a(r*cos(theta),r*sin(theta));
  return a;
}


int main() {

  return 0;
}
