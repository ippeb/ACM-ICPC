/* 
   Breadth First Search, Graph Traversal.

  (c) 2015 Josef Ziegler (ippeb24@gmail.com)

*/

#include <string>
#include <cstdio>
#include <queue>
#define MAXV 100 + 1
using namespace std;

int dist[MAXV];
vector<int> edges[MAXV]; /* adjacency info */
int parent[MAXV]; /* discovery relation */
bool discovered[MAXV]; /* which vertices have been found */
bool processed[MAXV]; /* which vertices have been processed */
int nedges, nvertices; /* number of edges and number of vertices in graph */

void process_vertex(int v){
  printf("processed vertex %d\n",v);
}
void process_edge(int x, int y){
  printf("processed edge (%d,%d)\n",x,y);
  nedges++;
}

void read(){
  int m,x,y;
  nedges=0;
  scanf("%d %d",&nvertices,&m);
  for (int i=1; i<=m; i++){
    scanf("%d %d",&x,&y); // directed
    edges[x].push_back(y);
  }
}


void bfs(int start){
  queue<int> Q; /* queue of vertices to visit */
  Q.push(start);
  discovered[start]=true;
  dist[start]=0;
  while (Q.empty()==false){
    int v=Q.front(); // current vertex
    Q.pop();
    process_vertex(v);
    processed[v]=true;
    if (dist[v]==-1)
      dist[v]=dist[parent[v]]+1;
    for (vector<int>::iterator it=edges[v].begin(); it!=edges[v].end(); ++it){
      int y=*it;
      if (discovered[y]==false){
	Q.push(y);
	discovered[y]=true;
	parent[y]=v;
      }
      if (processed[y]==false)
	process_edge(v,y);
    }
  }
}

void init(){
  memset(discovered,0,sizeof discovered);
  memset(processed,0,sizeof processed);
  memset(dist,-1,sizeof dist);
  memset(parent,-1,sizeof parent );
  for (int i=0; i<MAXV; ++i) edges[i].clear();
}
  
int main(){
  read();
  init();
  int first=2 ;
  bfs(first);
  printf("distance from vertex %d:\n\n",first);
  for (int i=1; i<=nvertices; i++)
    printf("%d) %d\n",i,dist[i]);
  printf("number of edges counted: %d\n",nedges);
}
  

