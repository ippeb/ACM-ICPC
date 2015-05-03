/*
  Hierholzer's Algorithm (Euler Tour Construction) ( O(E+V) ).

  Euler tour construction O(|E|+|V|) (tour: starting and end points may be 
  diifferent, circuit: same starting and endpoint).
  An adjacency matrix is used, since edges need to be deleted in O(1) to 
  guarantee linear time complexity.

  A graph has an Eulerian circuit if and only if it is connected (once you 
  throw out all nodes of degree 0) and every node has `even degree'.
  A graph has an Eulerian path if and only if it is connected and every node 
  except two has even degree. In the second case, one of the two nodes which 
  has odd degree must be the start node, while the other is the end node.

  USACO pseudocode:
  # circuit is a global array
  find_euler_circuit
    circuitpos = 0
    find_circuit(node 1)

  # nextnode and visited is a local array
  # the path will be found in reverse order
  
  find_circuit(node i)
    if node i has no neighbors then
      circuit(circuitpos) = node i
      circuitpos = circuitpos + 1
    else
      while (node i has neighbors)
          pick a random neighbor node j of node i
          delete_edges (node j, node i)
          find_circuit (node j)
      circuit(circuitpos) = node i
      circuitpos = circuitpos + 1


  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std; 

#define NVERTICES 100

int n=99; // number of distinct vertices
int   cp;
int   C[NVERTICES*NVERTICES];    
char  G[NVERTICES][NVERTICES];
int   Gdeg[NVERTICES];

void deledge(int a, int b){
  G[a][b]=0;
  G[b][a]=0;
  --Gdeg[a];
  --Gdeg[b];
  //  printf("edge (%d %d) deleted\n",a,b);
}
void addedge(int a, int b){
  G[a][b]=1;
  G[b][a]=1;
  ++Gdeg[a];
  ++Gdeg[b];
  //  printf("edge (%d %d) added\n",a,b);
}
void findcircuit(int s){
  if (!Gdeg[s]) C[cp++]=s;
  else {
    for (int i=1; i<=n&&Gdeg[s]>0; i++){
      if (!G[s][i]) continue;
      deledge(s,i); // delete edge
      findcircuit(i);
    }
    C[cp++]=s; 
  }
}
void findeulercircuit(){ // to find an euler tour, simply call this function with one of the two vertices which has an odd degree
  memset(C,0,sizeof 0);
  cp=0;
  findcircuit(1); // starting from node 1
}
int main(){
  int a,b;
  memset(G,0,sizeof G);
  while (scanf("%d %d",&a,&b)==2)  addedge(a,b);
  findeulercircuit();
  for (int i=0; i<cp-1; i++) printf("%d %d\n",C[i],C[i+1]);
}
    
