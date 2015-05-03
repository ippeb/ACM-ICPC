/* 
   Prim's Algorithm (Minimum Spanning Tree) O(n log n)

   (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <queue>
#include <list>
#define  MAXV 1001
#define MAXINT 1000000000
using namespace std;

int dist[MAXV];
int parent[MAXV];
int n,m;
list <pair<int,int> > weight[MAXV]; // adjacency list
list <pair<int,int> > :: iterator iter;
class pqnode{
public:
  int n;
    pqnode(int x=0){n=x;}
  bool operator<(const struct pqnode &p2) const{
    return dist[n] > dist[p2.n];}
};

void prim(int s){
  int y,W;
  int intree[MAXV];
  for (int i=1; i<=n; i++){
    dist[i]=MAXINT;
    parent[i]=-1;
    intree[i]=false;
  }
  dist[s]=0;
  priority_queue<pqnode> P;
  P.push(pqnode(s));
  while (P.empty()==false){
    int v=P.top().n;
    P.pop();
    intree[v]=true;
    for (iter=weight[v].begin(); iter!=weight[v].end(); iter++){
      y=iter->first;
      W=iter->second;
      if ((dist[y]>W) && (intree[y]==false)){
          parent[y]=v;
          dist[y]=W;
          P.push(pqnode(y));}
    }
  }
}

int main(){
  scanf("%d %d",&n,&m);
  for (int i=1; i<=m; i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    weight[a].push_back(make_pair<int,int> (b,c));
    weight[b].push_back(make_pair<int,int> (a,c));
  }
  prim(1);
  for (int i=1; i<=n; i++){
    printf("%d %d\n",i,parent[i]);
  }
}
    
