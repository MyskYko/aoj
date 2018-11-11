#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point{
  double x;
  double y;
  struct point *next;
}Point;

Point *create(double x, double y) {
  Point *p = (Point*)malloc(sizeof(Point));
  p->x = x;
  p->y = y;
  p->next = NULL;
  return p;
}

void create_next(double x, double y, Point *p0) {
  Point *p = create(x,y);
  p->next = p0->next;
  p0->next = p;
}

void rotation(Point *r,double seta) {
  double temp_x,temp_y;
  temp_x = r->x;temp_y = r->y;
  r->x = cos(seta)*temp_x-sin(seta)*temp_y;
  r->y = sin(seta)*temp_x+cos(seta)*temp_y;
}

void koch_curve(Point *begin) {
  Point *p1,*p2;
  p1 = begin;
  while(p1->next != NULL) {
    p2 = p1->next;
    Point *r = create((p2->x-p1->x)/3,(p2->y-p1->y)/3);
    create_next(p1->x+r->x,p1->y+r->y,p1);
    create_next(p1->next->x+r->x,p1->next->y+r->y,p1->next);
    rotation(r,M_PI/3);
    create_next(p1->next->x+r->x,p1->next->y+r->y,p1->next);
    p1 = p2;
  }
}

int main()
{
  int i,n;
  Point *begin,*p;
  begin = create(0,0);
  create_next(100,0,begin);
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
     koch_curve(begin); 
  }
  
  p = begin;
  while(p != NULL) {
    printf("%lf %lf\n", p->x, p->y);
    p = p->next;
  }
  
  return 0;
}
