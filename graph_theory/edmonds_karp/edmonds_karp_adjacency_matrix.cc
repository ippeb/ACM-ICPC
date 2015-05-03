/*
  Edmonds-Karp's Algorithm (Maxflow/Mincut) O(V*E^2).
  
  Edmonds-Karp's algorithm using Ford Fulkerson's method. Implementation uses
  adjacency matrices (implemented as 2D arrays) and vertex capacities of inf.

  Max-flow-min-cut theorem: a flow is maximum if and only if its residual 
  network contains no augmenting path => |f|=c(S,T) for some cut (S,T) of G.

  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#define MAXV 1000
#define inf 0x3f3f3f3f
using namespace std;

int N,E;           /* number of vertices and edges */
int C[MAXV][MAXV]; /* adjacency matrix, C[a][b] means edge (a,b) has a capacity of C[a][b] */

int edmonds_karp(int source,int sink){
  int flow[MAXV][MAXV];              /* adjacency matrix: flow */
  int pre[MAXV],p,que[MAXV],q;       /* que: a queue */
  int d[MAXV];

  if (source==sink) return inf;
  memset(flow,0,sizeof(flow)); /* initialize all flows to zero */
  while (true){  /* while there exists a path p from s to t in the residual network */
    memset(pre,-1,sizeof(pre)); // initialize pre array
    d[source]=inf;              // set residual capacity of source to infinity

    p=q=0;                      // initialize index of p pre and que
    que[q++]=source;            // add source to queue
    while(p<q and pre[sink]<0){ // while queue is not empty and sink was not yet visited 
      int t=que[p++],j;
      for (int i=0; i<N; i++)
	if (pre[i]<0 && (j=C[t][i]-flow[t][i]) ){ // i was not visited and residual flow is !=0
	  pre[que[q++]=i]=t;
	  d[i]=min(d[t],j);}
    }
    if (pre[sink]<0) break;

    for (int i=sink; i!=source; i=pre[i]){ /* augment path */
      flow[pre[i]][i]+=d[sink];
      flow[i][pre[i]]-=d[sink];
    }
  }
  
  int j,i;
  for (j=i=0; i<N; j+=flow[source][i++]);
  return j;
}

/* INPUT restriction:
   assuming all vertices are of the form:
   V={0, 1, .., N-1}
   and that the graph is directed
*/

int main(){
  int s,t;                 /* source and sink vertex */
  scanf("%d %d",&N,&E);
  scanf("%d %d",&s,&t);

  for (int i=0; i<E; i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    C[a][b]=c;
    //    C[b][a]=c;             /* if undirected graph */
  }

  printf("%d\n",edmonds_karp(s,t));
}
