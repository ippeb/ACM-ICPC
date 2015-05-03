/* 
   Dijkstra's Algorithm O(n log n) using STL list.

   Computes the one-source shortest path in weighted graphs in O(n log n)
   using STL list.
   
   (c) 2015 Josef Ziegler
   
*/

#include <cstdio>
#include <list>
#include <queue>
#define MAXV 10000
#define INF 2000000
using namespace std;

int dist[MAXV];
int parent[MAXV];
int n,m;
list <pair<int,int> > weight[MAXV]; // adjacency list; weight(a) contains (b,w)
                                    // means edge from a to b with weight w
list <pair<int,int> >:: iterator iter;

class pqnode{
public:
  int n;
  pqnode (int x=0) {
    n = x;}
  bool operator<(const struct pqnode p2) const{
    return dist[n] > dist[p2.n];}
};

void dijkstra(int s){
  int y,W;
  priority_queue<pqnode> P;
  for (int i=1; i<=n; i++){
    dist[i] = INF;
    parent[i] = -1;}
  
  dist[s]=0;
  P.push(pqnode(s));
  while (P.empty()==false){
    int k=P.top().n;
    P.pop();
    for (iter = weight[k].begin(); iter!=weight[k].end(); iter++){
      y = iter->first;
      W = iter->second;
      if (dist[y] > dist[k]+W){
	dist[y]=dist[k]+W;
	parent[y]=k;
	P.push(pqnode(y));
      }
    }
  }
}

int main(){
  scanf("%d %d",&n,&m);
  for (int i=1; i<=m; i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    weight[a].push_back(make_pair<int,int> (b,c)); // directed
  }
  dijkstra(1);
  for (int i=1; i<=n; i++){
    printf("%d: %d\n",i,dist[i]);
  }
}
  
