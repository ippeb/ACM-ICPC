/* 
   ArticFind.

   Finds all articulation points of an undirected connected graph 
   in O(E). The DFS tree is built starting with root: vertex number 0.

   INPUT: N,M (N vertices, M edges)
   OUTPUT: S (number of articulation points)
           Followed by S integers, the articulation points


   (c) 2015 Josef Ziegler

*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <ctime>
// #define NDEBUG
#include "assert.h"
#include "string.h"
#define MP make_pair
#define COMMENT 1
#define MAX 50001
using namespace std;

typedef unsigned uint;
typedef long long int llint;
typedef pair<int,int> PII;

int N,M,a,b;
int parent[MAX];
vector<int> G[MAX];
vector<int> back[MAX]; /* back edges */
bool B[MAX];
int DFN[MAX],L[MAX]; /* DFN[i] time at which i is visited (starting with 1), L[i] smallest DFN value which can be visited from i through a special path, if none exists L[i]=DFN[i] */
int num;
vector<int> arc; // for counting articulation points


void dfs_artic(int s){
  B[s]=true;
  for (vector<int> :: iterator it=G[s].begin(); it!=G[s].end(); it++){
    if (!B[*it]) {
      DFN[*it]=num++;
      L[*it]=DFN[*it];
      parent[*it]=s;
      dfs_artic(*it); // recursion
      // check if s is an articulation point, that is, all vertices other than root
      if (s!=0 && DFN[s]<=L[*it]) arc.push_back(s);
    }
    else {
      if (*it!=parent[s]) { // back edge
	back[s].push_back(*it);
	L[s]=min(L[s],DFN[*it]);
      } 
    }
  }
		// todo: not execute for root
  L[parent[s]]=min(L[parent[s]],L[s]); // update parent
  
}
    
    

int main(){
  scanf("%d %d",&N,&M);
  for (int i=0; i<M; i++){
    scanf("%d %d",&a,&b);
    G[a].push_back(b);
    G[b].push_back(a); // undirected graph 
  }

  memset(B,0,sizeof B);
  memset(parent,-1,sizeof parent);
  num=1;
  DFN[0]=num++;
  dfs_artic(0); // always start dfs with vertex 0

#if COMMENT
  printf("PARENT relation\n");
  for (int i=0; i<N; i++) printf("%d: %d\n",i,parent[i]);
  printf("\n");
  printf("back edges\n");
  for (int i=0; i<N; i++){
    printf("%d: ",i);
    for (vector<int>::iterator it=back[i].begin(); it!=back[i].end(); it++)
      printf("%d ",*it);
    printf("\n");
  }
  printf("\n");
  printf("vertex no. i, DFN[i], L[i]\n");
  for (int i=0; i<N; i++) printf("%d: %d %d\n",i,DFN[i],L[i]);
#endif 

  /* check root */
  int cnt=0;
  for (int i=0; i<N; i++) if (parent[i]==0) cnt++;
  if (cnt>1) {
    arc.push_back(0);}
  printf("there are %d articulation points\n",arc.size());
  for (vector<int>::iterator it=arc.begin(); it!=arc.end(); it++)
    printf("%d\n",*it);
}

