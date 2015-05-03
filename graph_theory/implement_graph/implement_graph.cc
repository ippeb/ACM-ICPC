/*
  Useful operations for building a graph.

  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <string>
using namespace std;

#define MAXV 100     /* maximum number of vertices */
#define MAXDEGREE 50 /* maximum vertex outdegree */

typedef struct {
  int edges[MAXV+1][MAXDEGREE]; /* adjacency info */
  int degree[MAXV+1];           /* outdegree of each vertex */
  int nvertices;                /* number of vertices in graph */
  int nedges;                   /* number of edges in graph */
} graph;

void initialize(graph *g){
  g->nvertices = 0;
  g->nedges = 0;
  memset(g->degree,0,MAXV+1);}

void insert_edge(graph *g, int x, int y, bool directed){
  g->edges[x][g->degree[x]++] = y;
  if (!directed) insert_edge(g,y,x,true);
  else g->nedges++;}

void read(graph *g, bool directed){
  int m;   /* number of edges */
  int x,y; /* vertices in edge (x,y) */
  initialize(g);
  scanf("%d %d",&(g->nvertices),&m);
  for (int i=1; i<=m; i++){
    scanf("%d %d",&x,&y);
    insert_edge(g,x,y,directed);}
}

void print(graph *g){
  for (int i=1; i<=g->nvertices; i++){
    printf("%d: ",i);
    for (int j=0; j<g->degree[i]; j++){
      printf(" %d",g->edges[i][j]);}
    putchar(10);
  }
}

int main(){
  graph g;
  read(&g,true);
  print(&g);
}
					      
