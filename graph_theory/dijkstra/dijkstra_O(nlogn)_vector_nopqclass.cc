/*
   Dijkstra's Algorithm O(n log n) using STL vector.

   Computes the one-source shortest path in weighted graphs in O(n log n)
   using STL vector and a pq struct used for the priority queue.
   
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
vector <pair<int,int> > weight[MAXV]; // adjacency list; weight(a) contains (b,w)
                                      // means edge from a to b with weight w
vector <pair<int,int> >:: iterator iter;

struct pq{
  bool operator()(int a, int b){
    return dist[a]>dist[b];
  }
};

void dijkstra(int s){
  int y,W;
  priority_queue<int,vector<int>, pq> P;
  for (int i=1; i<=n; i++){
    dist[i] = INF;
    parent[i] = -1;}
  
  dist[s]=0;
  P.push(s);
  while (P.empty()==false){
    int k=P.top();
    P.pop();
    for (iter = weight[k].begin(); iter!=weight[k].end(); iter++){
      y = iter->first;
      W = iter->second;
      if (dist[y] > dist[k]+W){
	dist[y]=dist[k]+W;
	parent[y]=k;
	P.push(y);
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
  
