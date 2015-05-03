/*
  Depth-First Search, Graph Traversal.

  (c) 2015 Josef Ziegler (ippeb24@gmail.com)

*/

#include <cstdio>
#include <string>
#define MAXV 1000+1
#define MAXDEGREE 1000

int edges[MAXV][MAXDEGREE]; /* adjacency info */
int degree[MAXV];           /* outdegree of each vertex */
int parent[MAXV];           /* discovery relation */
bool discovered[MAXV];      /* which vertices have been found */
bool processed[MAXV];       /* which vertices have been processed */
int nvertices,nedges;
bool finished=false;

void init(){
  memset(processed,0,sizeof processed);
  memset(discovered,0,sizeof discovered);
  memset(parent,-1,sizeof parent);
  memset(degree,0,sizeof degree);
}

void process_vertex(int v){
  printf("processed vertex %d\n",v);
}

void find_path(int start, int end){
  if ((start==end) || (end==-1))
    printf("\n%d",start);
  else{
    find_path(start,parent[end]);
    printf(" %d",end);}
}

void process_edge(int x,int y){
  if (parent[x]!=y){ /* found back edge */
    printf("Cycle from %d to %d\n",y,x);
    find_path(y,x);
    finished=true;}
}
  bool valid_edge(int v){
  return true;}


void read(){
  int m,x,y;
  init();
  nedges=nvertices=0;
  scanf("%d %d",&nvertices,&m);
  for (int i=1; i<=m; i++){
    scanf("%d %d",&x,&y);
    edges[x][degree[x]++]=y;
    edges[y][degree[y]++]=x;
   }
}
	     

void dfs(int v){
  int y; /* successor vertex */
  discovered[v]=true;
  process_vertex(v);
  if (finished) return;
  for (int i=0; i<degree[v]; i++){
    y=edges[v][i];
    if (valid_edge(y)==true){
      if (discovered[y]==false){
	parent[y]=v;
	dfs(y);
      } else if (processed[y]==false)
	process_edge(v,y);
    }
    if (finished) return;
  }
  processed[v]=true;
}
    
    
int main(){
  /* undirected */
  read();
  dfs(1);
}
