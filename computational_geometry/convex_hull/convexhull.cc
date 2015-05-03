/*
  Graham's Scan Algorithm (Convex Hull).

  Computes the convex hull for a given polygon. 
  The convex hull is the smallest polygon, that contains every one of the 
  points in the original set.

  (c) 2015 Josef Ziegler

*/

#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INF 1e9
#define EPSILON (1e-7)
#define MAXN 100000
#define PDD pair<double,double>
using namespace std;

int N; /* number of points */
vector< PDD > V; /* vector of N points, x-, and y-coordinate */
PDD F;          /* first hull point, the one with the lowest y coordinate 
		                  (if there's a tie -> lowest x coordinate) */
PDD S;
PDD C[MAXN]; /* convex hull */
map< PDD , bool> M;
/* A := signed area of triangle: p1p2 x p1p3
   if A > 0 => ccw, if A < 0 => cw */
bool ccw(PDD a, PDD b, PDD c){
  return (b.first-a.first) * (c.second-a.second) - (c.first-a.first) * (b.second-a.second) >= 0;}

bool collinear(PDD a, PDD b, PDD c){
  /* signed triangle area */
  double tmp=(b.first-a.first) * (c.second-a.second) - (c.first-a.first) * (b.second-a.second);
  return (tmp<EPSILON && tmp>-EPSILON);}

double dist(PDD a, PDD b){
return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));}

bool sortop(PDD a, PDD b){
  if (collinear(F,a,b))
    if (dist(F,a) < dist(F,b)) return 1;
    else return 0;
  if (ccw(F,a,b)) return 1;
  else return 0;
}

int main(){
  /* input handling */
  scanf("%d",&N);         
  for (int i=0; i<N; i++){
    scanf("%lf %lf",&(S.first),&(S.second)); 
    printf("%.0lf %.0lf\n",S.first,S.second);
    if (M.find(S)==M.end()){
      V.push_back(S);
      M[S]=true;}
  }

  N=V.size();
   /* find first hull point */
  F=make_pair<double,double> (INF,INF);
  for (int i=0; i<N; i++) 
    if (V[i].second < F.second) F=V[i];
    else if (V[i].second==F.second) if (V[i].first < F.first) F=V[i];
  printf("first hull point: %.0lf %.0lf\n",F.first,F.second);
  /* sort points according to the cotangent of the angle they and point F make with the x-axis */
  sort(V.begin(),V.end(),sortop); 
    
  /* for each point determine whether moving from the two previously considered points to this point is cw or ccw and 
     move on */
  int k=2,last=1;
  C[0]=V[0]; 
  C[1]=V[1];
	V.push_back(V[0]); // V[N]=V[0] not save since V vector from 0 to N-1
  while (k<=N){
    if (ccw(C[last-1],C[last],V[k])){
      last++;
      C[last]=V[k];
      k++;}
    else 
      last--;
  }
  
  /* print solution */
  printf("sorted\n");
  for (int i=0; i<N; i++) printf("%.0lf %.0lf\n",V[i].first,V[i].second);
  printf("\n\n\nconvex hull\n");
  for (int i=0; i<last; i++) printf("%.0lf %.0lf\n",C[i].first,C[i].second);
}
