/*
  Dinic's Algorithm (Maxflow/Mincut) O(V^2*E).

  Dinic's algorithm for solving the maximum flow problem.

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
using namespace std;

typedef unsigned uint;
typedef long long int llint;
typedef pair<int,int> PII;

// the maximum number of vertices
#define NN 1024

// adjacency matrix (fill this up)
// If you fill adj[][] yourself, make sure to include both u->v and v->u.
int C[NN][NN], deg[NN], adj[NN][NN];
// BFS stuff
int que[NN], pre[NN];

int dinic( int n, int s, int t ){
  int flow = 0;
  while( true ){
    // find an augmenting path
    memset( pre, -1, sizeof pre);
    int qf = 0, qb = 0;
    que[qb++] = s;
    pre[s]=-2;
    while( qf < qb && pre[t] == -1 )
      for( int u = que[qf++], i = 0, v; i < deg[u]; i++ )
	if( pre[v = adj[u][i]] == -1 && C[u][v] )
	  pre[que[qb++] = v] = u;
    
    // see if we're done
    if( pre[t] == -1 ) break;
    
    // try finding more paths
    for( int z = 0; z < n; z++ ) if( C[z][t] && pre[z] != -1 ){
	int bot = C[z][t];
	for( int v = z, u = pre[v]; u >= 0; v = u, u = pre[v] )
	  bot=min(bot,C[u][v]);
	if( !bot ) continue;
	
	C[z][t] -= bot;
	C[t][z] += bot;
	for( int v = z, u = pre[v]; u >= 0; v = u, u = pre[v] ){
	  C[u][v] -= bot;
	  C[v][u] += bot;}
	flow += bot;
      }
  }
  return flow;
}

//----------------- EXAMPLE USAGE -----------------
int main()
{
  // read a graph into C[][]
  memset( C, 0, sizeof( C ) );
  int n, s, t, m;
  scanf( " %d %d %d %d", &n, &s, &t, &m );
  while( m-- )
    {
      int u, v, c; scanf( " %d %d %d", &u, &v, &c );
      C[u][v] = c;
    }

  // init the adjacency list adj[][] from C[][]
  memset( deg, 0, sizeof( deg ) );
  for( int u = 0; u < n; u++ )
    for( int v = 0; v < n; v++ ) if( C[u][v] || C[v][u] )
				   adj[u][deg[u]++] = v;

  printf( "%d\n", dinic( n, s, t ) );
  return 0;
}
