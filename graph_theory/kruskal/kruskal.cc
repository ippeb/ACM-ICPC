/* 
   Kruskal's Algorithm (Minimum Spanning Tree) O(n log n).

   (c) 2015 Josef Ziegler

*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <complex>
#define MP              make_pair
#define CMNT            1
#define INF             0x3fffffff
#define MM(s,a)         memset((s),(a),sizeof((s)))
using namespace std;

typedef unsigned           uint;
typedef long long int     llint;
typedef pair<int,int>       PII;
typedef pair<double,double> PDD;
typedef pair<int,PII>       PIP;

vector<int> id; // id[i]: id of vertex i (used for union-find)
vector<int> sz; // sz[i]: size of the component containing vertex i
vector<vector<PII> > V;

void initialize(vector<int> &id, vector<int> &sz, int N){
  for (int i=0; i<N; i++){
    id[i]=i;
    sz[i]=1;}
}
    
int root(vector<int> &id, int i){
  while (id[i]!=i){
    id[i]=id[id[i]]; // path compression
    i=id[i];}
  return i;
}
 
bool find(vector<int> &id, int p, int q){ // are p and q in the same set?
  return root(id,p)==root(id,q);
}
  
void unite(vector<int> &id, vector<int> &sz, int p, int q){ // merge sets containing i and j
  int i=root(id,p);
  int j=root(id,q);
  if (sz[i]<sz[j]){sz[j]+=sz[i]; id[i]=j;}
  else            {sz[i]+=sz[j]; id[j]=i;}
}


int kruskal(int N){ // N: number of vertices
  set<PIP> S;
  int sol=0;
  for (int i=0; i<N; i++)
    for (vector<PII>::iterator it=V[i].begin(); it!=V[i].end(); it++)
      S.insert(MP(it->second,MP(i,it->first)));
  while (!S.empty()){
    PIP v=*S.begin();
    S.erase(S.begin());
    //    printf("at %d %d cost %d\n",v.second.first,v.second.second,v.first);
    if (!(find(id,v.second.first,v.second.second))){
      sol+=v.first;
      unite(id,sz,v.second.first,v.second.second);
    }
  }
  return sol;
}

int N,M;

int main(){
  scanf("%d %d",&N,&M);
  
  id.resize(N+1);
  sz.resize(N+1);
  V.resize(N+1);
  initialize(id,sz,N);
  
  for (int i=0; i<M; i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    --a; --b; // indexed from 0 to N-1
    V[a].push_back(MP(b,c));
    V[b].push_back(MP(a,c));
  }
  printf("%d\n",kruskal(N));
}
  
