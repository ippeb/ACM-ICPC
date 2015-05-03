/*
  Ford Fulkerson's Algorithm with Capacity Scaling (Maxflow/Mincut).

  The run-time complexity is O(E^2 log C), C = maxflow.
  
  (c) 2015 Josef Ziegler

*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <ctime>
// #define NDEBUG
#include "assert.h"
#include "string.h"
#define MP make_pair
#define COMMENT 1
#define MAXV 100
using namespace std;

typedef unsigned uint;
typedef long long int llint;
typedef pair<int,int> PII;


int M,N,C[MAXV][MAXV]; // #edges, #vertices, capacity matrix
bool B[MAXV];
int s,t; // source, sink
int w; // used for capacity scaling

bool inc(int x){
  if (x==t) return true;
  B[x]=true;
  for (int y=0; y<=N; y++){
    if (C[x][y]>=w and !B[y] and inc(y)){
      C[x][y]-=w;
      C[y][x]+=w;
      return true;
    }
  }
  return false;
}
  

int main(){
  scanf("%d %d",&N,&M); 
  scanf("%d %d",&s,&t);
  memset(C,0,sizeof C);
  int maxc=0;
  for (int i=0; i<M; i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    maxc=max(c,maxc);
    C[a][b]=c; // 
    // C[b][a]=c; if undirected
  }
  w=maxc;
  int sol=0;
  while (w>0){
    memset(B,0,sizeof B);
    if (inc(s)) sol+=w; 
    else w/=2;
  }
  printf("%d\n",sol);
}
	    
