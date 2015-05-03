/* 
   Prim's Algorithm (Minimum Spanning Tree) O(n^2) 

   (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <string>
#define MAXV 101
#define MAXDEGREE 101
#define MAXINT 2000000000
using namespace std;

int edges[MAXV][MAXDEGREE];  /* adjacency info */
int degree[MAXV];            /* outdegree of each vertex */
int parents[MAXV];           /* discovery relation */
int weight[MAXV][MAXDEGREE]; /* edge weight */
int nvertices, nedegs;       /* number of vertices and edges of graph */

void read(){
  int x,y,m,c;
  memset(degree,0,sizeof degree);
  scanf("%d %d",&nvertices,&m);
  for (int i=0; i<m; i++){
    scanf("%d %d %d",&x,&y,&c);
    weight[x][degree[x]]=c;
    edges[x][degree[x]++]=y; // undirected graph
    weight[y][degree[y]]=c;
    edges[y][degree[y]++]=x;}
}

int prim(int start){
  bool intree[MAXV];          /* is vertex in tree yet? */  
  int distance[MAXV];         /* vertex distance from start */
  int v,w;            /* current vertex to process, candidate next vertex */
  int dist, Weight;   /* shortest current distance, edge weight */  

  for (int i=1; i<=nvertices; i++){
    parents[i]=-1;
    intree[i]=false;
    distance[i]=MAXINT;}
  
  distance[start]=0;
  v=start;
  while (intree[v]==false){
    intree[v]=true;
    for (int i=0; i<degree[v]; i++){
      w=edges[v][i];
      Weight=weight[v][i];
      if ((distance[w] > Weight) && (intree[w]==false)){
	distance[w]=Weight;
	parents[w]=v;}
    }
    v=1;
    dist=MAXINT;
    for (int i=1; i<=nvertices; i++){
      if ((intree[i]==false) && (dist > distance[i])){
	dist = distance[i];
	v=i;}
    }
  }
}

int main(){
  read();
  prim(1);
  printf("parents: \n");
  for (int i=1; i<=nvertices; i++)
    printf("%d: %d\n",i,parents[i]);
}
  
