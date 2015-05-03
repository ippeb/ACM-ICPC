/* 
   Dijkstra's Algorithm O(n^2).

   Computes the one-source shortest path in weighted graphs in O(n^2).
   
   (c) 2015 Josef Ziegler
   
*/

#include <cstdio>
#include <string>
#define MAXINT 1000000000
#define MAXV 1001
#define MAXDEGREE 1001
using namespace std;

int edges[MAXV][MAXDEGREE]; /* adjacency info */
int degree[MAXV];           /* outdegree of each vertex */
int nvertices,nedges;       /* number of vertices and edges in graph */
int parent[MAXV];           /* records tree topology */
int weight[MAXV][MAXDEGREE];/* edge weight info */
int Weight;                 /* edge weight */
int dist;                   /* shortest current distance */
int v,w;                 /* current vertex to process, candidate next vertex*/
int Distance[MAXV];  /* vertex Distance from start */

void read(){
  int x,y,m,c;
  scanf("%d %d",&nvertices,&m);
  for (int i=0; i<m; i++){
    scanf("%d %d %d",&x,&y,&c);
    weight[x][degree[x]]=c;
    edges[x][degree[x]++]=y;
  }
}

void dijkstra(int start){
  bool intree[MAXV];   /* is vertex in tree yet? */
  for (int i=1; i<=nvertices; i++){
    intree[i]=false;
    Distance[i]=MAXINT;
    parent[i]=-1;}
  
  Distance[start]=0;
  v=start;
  while (intree[v]==false){
    intree[v]=true;
    for (int i=0; i<degree[v]; i++){
      w=edges[v][i];
      Weight=weight[v][i];
      if (Distance[w] > (Distance[v]+Weight)){
	Distance[w]=Distance[v]+Weight;
	parent[w]=v;}
    }
    v=1;
    dist=MAXINT;
    for (int i=1; i<=nvertices; i++){
      if ((dist > Distance[i]) && (intree[i]==false)){
	v=i;
	dist = Distance[i];
      }
    }
  }
}

void find_path(int start, int end){
  if ((start==end) || (end==-1))
    printf(" %d\n",start);
  else {
    find_path(start,parent[end]);
    printf(" %d\n",end);
  }
}
      
      
int a,b;

int main(){
  read();
  for (int i=1; i<=nvertices; i++)
    for (int j=0; j<degree[i]; j++)
      printf("%d) %d %d\n",i,edges[i][j],weight[i][j]);
  while (1){
    printf("shortest path + route from 1 to b:\n");
    scanf("%d %d",&a,&b);
    dijkstra(a);
    printf("distance: %d\n",Distance[b]);
    find_path(a,b);}
}
  
