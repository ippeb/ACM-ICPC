/* Graph Traversal: Depth-First Search */

#include <cstdio>
#include <string>
#include <vector>
#define MAXV 1000
using namespace std;

vector<int> edges[MAXV];    /* adjacency info */
int parent[MAXV];           /* discovery relation */
bool discovered[MAXV];      /* which vertices have been found */
bool processed[MAXV];       /* which vertices have been processed */
int nvertices,nedges;
bool finished;

void init(){
  memset(processed,0,sizeof processed);
  memset(discovered,0,sizeof discovered);
  memset(parent,-1,sizeof parent);
  for (int i=0; i<MAXV; ++i) edges[i].clear();
  finished=false;
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

void read(){
  int x,y;
  init();
  nedges=nvertices=0;
  scanf("%d %d",&nvertices,&nedges);
  for (int i=1; i<=nedges; i++){
    scanf("%d %d",&x,&y);
    edges[x].push_back(y);
    edges[y].push_back(x);
   }
}
	     

void dfs(int v){
  discovered[v]=true;
  process_vertex(v);
  if (finished) return;
  for (vector<int>::iterator it=edges[v].begin(); it!=edges[v].end(); ++it){
    int y=*it; /* successor vertex */
    if (discovered[y]==false){
      parent[y]=v;
      dfs(y);
    } else if (processed[y]==false){
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
