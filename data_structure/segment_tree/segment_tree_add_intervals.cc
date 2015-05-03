/*
  Segment Tree (Add Intervals).

  A segment tree is a heap-like data structue that can be used for making 
  update/query operations upon array intervals in O(log N).
  In this example it is used to add intervals. 
  Note, this could also be solved using fenwick/binary indexed trees.

  (c) 2015 Josef Ziegler

*/

#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 9
#define MAXIND 32
using namespace std;


void initialize(int M[MAXIND] ){
  memset(M,0,MAXIND*sizeof(int));
}

// b and e denote beginning and end of interval (inclusive), usually b=0, e=N-1
// add interval [i,j]
void add_interval(int node, int b, int e, int M[MAXIND], int i, int j){
  if (i>e || j<b) return;
  if (b>=i && e<=j) {
    M[node]++;
    return;
  }
  add_interval(2*node  , b, (b+e)/2,  M, i, j);
  add_interval(2*node+1, (b+e)/2 +1, e, M, i, j);
}

// initialize A to zero before calling this function
// (version 2) takes O(n log n)
void save_interval(int node, int b, int e, int M[MAXIND], int A[MAXN]){
  if (M[node]>=1) {
    for (int k=b; k<=e; ++k) A[k]=1; // A[k]+=M[node]; (version 2)
    return; // no return (version 2)
  }
  if (b==e) return;
  save_interval(node*2,   b,   (b+e)/2, M, A);
  save_interval(node*2+1, (b+e)/2+1, e, M, A);
}

int main(){
  // call both functions with node=1, b=0, e=N-1
  int M[MAXIND], a, b;
  initialize(M);
  while (1){
    scanf("%d %d",&a, &b); // read interval which will be stored
    add_interval(1, 0, MAXN-1, M, a, b);

    /* for printing */
    int A[MAXIND]; 
    for (int i=0; i<MAXN; ++i) A[i]=0;
    save_interval(1,0,MAXN-1,M,A);
    for (int i=0; i<MAXN; ++i)
      printf("%d: %d\n",i,A[i]);
    printf("\n");

    /*
    bool found=false;
    for (int i=0; i<MAXN; ++i){
      if (A[i]>0 && !found) {
	found=true;
	printf("[%d ",i);
      }
      if (found && (A[i]==0)) {
	printf("%d] ",i-1);
	found=false;
      }
    }
    if (found) printf("%d]",MAXN-1);
    printf("\n");
    */
    /* end printing */
  }
}
    
      
      
  
