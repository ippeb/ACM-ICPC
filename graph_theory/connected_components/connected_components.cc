/* 

   Connected Components.

   Finds cycles and counts connected components in an undirected graph via dfs.

   (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <string>
#define MAXV 1000+1
#define MAXDEGREE 100
using namespace std;

int edges[MAXV][MAXDEGREE]; /* adjacency info */
int degree[MAXV];           /* outdegree of each vertex */
int parent[MAXV];           /* discovery relation */
bool discovered[MAXV];      /* which vertices have been found */
bool processed[MAXV];       /* which vertices have been processed */
int nedges, nvertices;      /* number of edges and vertices of graph */
bool finished=false;

void init(){
  memset(discovered,0,sizeof discovered);
  memset(processed,0,sizeof processed);
  memset(parent,-1,sizeof parent);
  memset(degree,0,sizeof degree);
  finished=false;
  nedges=0;
}

void process_edge(int x, int y){
}

void process_vertex(int v){
  printf("%d ",v);
}

bool valid_edge(int v){
  return true;}

void dfs(int v){
  int y;
  if (finished) return;
  discovered[v]=true;
  process_vertex(v);
  for (int i=0; i<degree[v]; i++){
    y=edges[v][i];
    if (valid_edge(y)==true){
      if (discovered[y]==false){
	parent[y]=v;
	dfs(y);}
      else if (processed[y]==false){
	process_edge(v,y);}
    }
    if (finished) return;
  }
  processed[v]=true;
}
  
void read(){
  int x,y,m;
  scanf("%d %d",&nvertices,&m);
  for (int i=1; i<=m; i++){
    scanf("%d %d",&x,&y); // undirected graph only
    edges[x][degree[x]++]=y;
    edges[y][degree[y]++]=x;
  }
}

int connected_component(){
  int c=0;
  for (int i=1; i<=nvertices; i++){
    if (discovered[i]==false){
      c++;
      printf("%d) ",c);
      dfs(i);
      printf("\n");}
  }
  return c;
}
      
int main(){
  init();
  read();
  printf("number of components: %d\n",connected_component());
}
