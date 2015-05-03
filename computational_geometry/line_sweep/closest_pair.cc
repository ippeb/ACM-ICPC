/*
  Closest Pair of Points (Line Sweep)

  Determines closest pair of points (Euclidean distance), a typical line 
  sweep problem application. O(n log n).

  (c) 2015 Josef Ziegler

*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <complex>
#define MP              make_pair
#define CMNT            0
#define INF             0x3fffffff
#define MM(s,a)         memset((s),(a),sizeof((s)))
using namespace std;

typedef unsigned           uint;
typedef long long int     llint;
typedef pair<int,int>       PII;
typedef pair<double,double> PDD;

int N; // number of points
struct pt{
  double x;
  double y;
} A[40001];

struct obj1{
  bool operator() (pt a, pt b){ if (a.x==b.x) {return a.y<b.y;} else {return a.x<b.x;}}
} compx;

struct obj2{
  bool operator() (pt a, pt b){ if (a.y==b.y) {return a.x<b.x;} else {return a.y<b.y;}}
} compy;

double dist(pt a, pt b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

multiset<pt,obj2> S; // needs to be multiset, since points with same coords are allowed

double d;

int main(){
  //    while (1){
  // initialize
  S.clear();
  // read input
  scanf("%d",&N);
  if (!N) return 0;
  for (int i=0; i<N; i++) scanf("%lf %lf",&(A[i].x),&(A[i].y)); 
  // A. order my points by the x coordinate
  sort(A,A+N,compx); 
  // B. multiset<pt,obj2> S: maintain an active set of points - candidates to be a closest-pair with the current point.
  //    the set is ordered by the y coordinate
  int back=0;
  d=dist(A[0],A[1]);
  S.insert(A[0]);  S.insert(A[1]);
  // C. line sweep the points by x order
  for (int i=2; i<N; i++){ 
    S.insert(A[i]); // insert new point into 'event set'
    multiset<pt,obj2>::iterator pos=S.find(A[i]),tmp;
    // C-1. scan the active set for points that may be closer to the current point than the shortest distance
    // compare with ones above A[i]
    tmp=pos;
    tmp++;
    while (tmp!=S.end() && (tmp->y-pos->y)<d){
      d=min(dist(*tmp,*pos),d);
      tmp++;}
    // compare with ones below A[i]
    tmp=pos;
    if (tmp!=S.begin()){
      tmp--;
      while ((pos->y-tmp->y)<d){
	d=min(d,dist(*tmp,*pos));
	if (tmp==S.begin()) break;
	tmp--;}
    }
    // C-2. Update the active set - keep only the points whose distance with the current point is at most the shortest distance
    for (;A[i].x-A[back].x>d && back<i; back++)
      S.erase(S.find(A[back]));
  }
  printf("%.6lf\n",d);
  //  }
}


