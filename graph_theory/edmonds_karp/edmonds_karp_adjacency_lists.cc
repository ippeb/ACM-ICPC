/*
  Edmonds-Karp's Algorithm (Maxflow/Mincut) O(V*E^2).
  
  Edmonds-Karp's algorithm using Ford Fulkerson's method. Implementation uses
  adjacency lists (implemented as vectors) and vertex capacities of inf.

  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include "string.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include "assert.h"
#include <map>
#include <set>
#include <utility>
#define MP make_pair
#define COMMENT 0
#define inf 1000000000
#define MAXV 10000
#define MAXE 50000
#define MAXL MAXV+4*MAXE (+MAXV)
using namespace std;

typedef pair<int,int> PII;
typedef long long llint;

// input restriction: undirected graph, no self-loops

int n,m;
map<PII,PII> M; //( (a,b),(c,f)) edge a to b with capacity c and flow f
vector<int> V[2*(MAXV+1)]; // all capacities are equal 1

void e(int a, int b, int c){
  V[a].push_back(b);
  M.insert(MP(MP(a,b),MP(c,0)));  
}

int edmonds_karp(int source, int sink){
  int pre [2*(MAXV+1)],que[2*(MAXV+1)],d[2*(MAXV+1)],p,q;
  if (sink==source) return inf;
  while (1){
    memset(pre,-1,sizeof pre);
    p=q=0;
    d[source]=inf;
    que[q++]=source;
    while (p<q and pre[sink]<0){
      int t=que[p++],tmp;
      for (vector<int>::iterator it=V[t].begin(); it!=V[t].end(); it++){
	PII edge=M[MP(t,*it)];
	if (pre[*it]<0 and (tmp=edge.first-edge.second)){
	  d[*it]=min(d[t],tmp);
	  pre[*it]=t;
	  que[q++]=*it;}
      }
    }
    if (pre[sink]<0) break;
    for (int i=sink; i!=source; i=pre[i]){
      M[MP(pre[i],i)].second+=d[sink];
      M[MP(i,pre[i])].second-=d[sink];
    }
  }
  
  int sol=0;
  for (vector<int>::iterator it=V[source].begin(); it!=V[source].end(); it++){
    sol+=M[MP(source,*it)].second;}
  return sol;
}

 int main(){
   int s,t;
   scanf("%d %d",&n,&m);
   scanf("%d %d",&s,&t);
   M.clear();
   for (int i=0; i<=2*(n+1); i++) V[i].clear();
   for (int i=0; i<m; i++){
     int a,b,c;
     scanf("%d %d %d",&a,&b,&c); // undirected
     e(2*a+1,2*b,c);
     e(2*b,2*a+1,0); 
     e(2*b+1,2*a,c);
     e(2*a,2*b+1,0);
   }
   
   for (int i=1; i<=n; i++){
     e(2*i,2*i+1,inf);
     e(2*i+1,2*i,0);}
   printf("%d\n",edmonds_karp(2*s+1,2*t));
 }

