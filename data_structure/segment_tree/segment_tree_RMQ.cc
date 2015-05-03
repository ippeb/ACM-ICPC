/*
  Segment Tree (RMQ).

  A segment tree is a heap-like data structue that can be used for making 
  update/query operations upon array intervals in O(log N).
  In this example it is used to solve Range-Minimum-Queries (RMQs).

  (c) 2015 Josef Ziegler

*/

#define COMMENT 1
#define MAXN 1000
#define MAXIND 2049 // actually 2*2^(9+1)
using namespace std;

typedef unsigned uint;
typedef long long int llint;
typedef pair<int,int> PII;

void initialize(int node, int b, int e, int M[MAXIND], int A[MAXN], int N){
  if (b==e) M[node]=b;
  else {
    initialize(2*node,  b, (b+e)/2, M, A, N);
    initialize(2*node+1,(b+e)/2+1,e,M, A, N);
    if (A[M[2*node]]<=A[M[2*node+1]]) M[node]=M[2*node];
    else M[node]=M[2*node+1];
  }
}

// find minimum value in some interval [i,j]
int query(int node, int b, int e, int M[MAXIND], int A[MAXN], int i, int j){
  int p1,p2;
  if (i>e || j<b) return -1;
  if (b>=i && e<=j) return M[node];
  p1=query(2*node  ,b,(b+e)/2,  M,A,i,j);
  p2=query(2*node+1,(b+e)/2+1,e,M,A,i,j);
  if (p1==-1) return M[node]=p2;
  if (p2==-1) return M[node]=p1;
  if (A[p1]<=A[p2]) return M[node]=p1;
  return M[node]=p2;
}

int main(){
  // call both functions with node=1, b=0, e=N-1
  ;
}
    
      
      
  
