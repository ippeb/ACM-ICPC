/*
  Line-Line Intersection.

  Adapted from the book "Programming Challenges" by Steven S. Skiena and 
  Miguel A. Revilla, 2003, Springer.

  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <cmath>
#include <string>
#include <cstdlib>
#define EPSILON (1e-7)
using namespace std;

typedef struct {
  double x;
  double y;
} point;

typedef struct {
  double a; /* x-coefficient */
  double b; /* y-coefficient */
  double c; /* constant term */
} line;

void points_to_line(point p1, point p2, line *l){
  if (p1.x == p2.x){ /* degeneracy */
    l->a = 1;
    l->b = 0;
    l->c = -p1.x;
  } else {
    l->a = -(p1.y - p2.y) / (p1.x - p2.x);
    l->b = 1;
    l->c = -(l->a * p1.x) - (l->b * p1.y);
  }
}

void point_and_slope_to_line(point p, double m, line *l){
  l->a = -m;
  l->b = 1;
  l->c = -((l->a * p.x) + (l->b * p.y));
}

bool parallelQ(line l1, line l2){
  return ((abs(l1.a - l2.a) <= EPSILON) && (abs(l1.b - l2.b) <= EPSILON));}

bool same_lineQ(line l1, line l2){
  return (parallelQ(l1,l2) && (abs(l1.c - l2.c) <= EPSILON));}
  
void intersection_point(line l1, line l2, point *p){
  if (same_lineQ(l1,l2)){ 
    p->x = 0.0; 
    p->y = 0.0; 
    return;}
  if (parallelQ(l1,l2)) return;
  p->x = (l2.b * l1.c - l1.b * l2.c) / (l1.b * l2.a - l2.b * l1.a);
  if (abs(l1.b) > EPSILON) /* test for vertical line */
    p->y = - (l1.a * (p->x) + l1.c);
  else
    p->y = - (l2.a * (p->x) + l2.c);}

double angle(line l1, line l2){ /* in radiants */
  if (parallelQ(l1,l2)) return 0.0;
  return atan((l1.a * l2.b - l2.a * l1.b)/(l1.a * l2.a + l1.b * l2.b));}

int main(){
  point A,B,I;
  line l1;
  scanf("%lf %lf",&(A.x),&(A.y));
  scanf("%lf %lf",&(B.x),&(B.y));
  points_to_line(A,B,&l1);
  printf("%.3flx + %.3fly + %.3fl = 0\n",l1.a,l1.b,l1.c);
}
