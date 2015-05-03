/* 
   Topological Sorting on DAGs.
   
   (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <string>
#include <queue>
#define MAXV 100 + 1
#define MAXDEGREE 100
using namespace std;

int nedges, nvertices; /* number of edges and number of vertices in graph */
int edges[MAXV][MAXDEGREE]; /* adjacency info */
int degree[MAXV]; /* outdegree of each vertex */
int parent[MAXV]; /* discovery relation */
bool discovered[MAXV]; /* which vertices have been found */
bool processed[MAXV]; /* which vertices have been processed */
int A[MAXV];

void compute_indegrees(int in[]){
  memset(in,0,sizeof A);
  for (int i=1; i<=nvertices; i++)
    for (int j=0; j<degree[i]; j++)
      in[edges[i][j]]++;
}

void topsort(int sorted[]){
  int indegree[MAXV]; /* indegree of each vertex */
  queue<int> Q;       /* vertices of indegree 0 */
  int x,y;            /* current and next vertex */
  compute_indegrees(indegree);
  for (int i=1; i<=nvertices; i++)
    if (indegree[i]==0)  Q.push(i);
  int j=0;
  while (Q.empty()==false){
    j++;
    x=Q.front();
    Q.pop();
    sorted[j]=x;
    for (int i=0; i<degree[x]; i++){
      y=edges[x][i];
      indegree[y]--;
      if (indegree[y]==0) Q.push(y);
    }
  }
  if (j!=nvertices)
    printf("NOT a DAG -- only %d vertices found\n",j);
}
  
void read(){
  int x,y,m;
  scanf("%d %d",&nvertices,&m);
  for (int i=1; i<=m; i++){
    scanf("%d %d",&x,&y);
    edges[x][degree[x]++]=y;}
}

int main(){
  read();
  topsort(A);
  for (int i=1; i<=nvertices; i++)
    printf("%d ",A[i]);
}
