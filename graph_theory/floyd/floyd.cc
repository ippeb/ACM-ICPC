/* 
   Floyd-Warshall (All Way Shortest Path).

   All-Pairs shortest path algorithm. 
   
   Path Reconstruction not implemented here, but can be implemented:
   Information to reconstruct all paths can be stored in an single N×N matrix 'next' 
   where next[i][j] represents the highest index vertex one must travel through if 
   one intends to take the shortest path from i to j. 
   
   if path[i][k] + path[k][j] < path[i][j] then
       path[i][j] := path[i][k]+path[k][j];
       next[i][j] := k;

   procedure GetPath (i,j)
   if path[i][j] equals infinity then
     return "no path";
   int intermediate := next[i][j];
   if intermediate equals 'null' then
     return " ";   // there is an edge from i to j, with no vertices between 
   else
     return GetPath(i,intermediate) + intermediate + GetPath(intermediate,j);

   (c) 2015 Josef Ziegler

 */

 
#include <cstdio>
#include <string>
#define MAXV 1001
#define MAXINT 1000000000
using namespace std;

int weight[MAXV][MAXV]; /* adjacency/weight info */
int nvertices;          /* number of vertices in graph */

void init(){
  nvertices=0;
  for (int i=0; i<MAXV; i++)
    for (int j=0; j<MAXV; j++)
      weight[i][j]=MAXINT;
}
   
void read(){
  int x,y,w,m; /* x,y,w placeholder for edge/weight; number of edges */
  init();
  scanf("%d %d",&nvertices,&m);
  for (int i=1; i<=m; i++){
    scanf("%d %d %d",&x,&y,&w); // undirected
    weight[x][y]=w;
  }
}

void floyd(){
  int k;         /* intermediate vertex counter */
  int through_k; /* distance through vertex k */
  for (k=1; k<=nvertices; k++)
    for (int i=1; i<=nvertices; i++)
      for (int j=1; j<=nvertices; j++){
	through_k = weight[i][k] + weight[k][j];
	if (through_k < weight[i][j])
	  weight[i][j] = through_k;}
}

int main(){
  read();
  floyd();
  for (int i=1; i<=nvertices; i++){
    for (int j=1; j<=nvertices; j++){
      printf("%d %d %d   ",i,j,weight[i][j]);}
    printf("\n");}

}
