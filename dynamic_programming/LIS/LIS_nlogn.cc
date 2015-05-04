/* 
   Longest (strictly) Increasing Subsequence O(n log n).

   Using a binary search approach.

   (c) 2015 Josef Ziegler
  
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <stack> 
#define COMMENT 0
using namespace std;

int N,X[10001],M[10001],P[10001],L;

int main(){
  scanf("%d",&N);
  for (int i=0; i<N; i++) scanf("%d",&X[i]);

#if COMMENT
  for (int i=0; i<N; i++) printf("%3d ",i);
  printf("\n");
  for (int i=0; i<N; i++) printf("----");
  printf("\n");
  for (int i=0; i<N; i++) printf("%3d ",X[i]);
  printf("\n\n");
#endif

  memset(P,-1,sizeof P); // this isn't needed - leave uninitialized
  memset(M,0,sizeof M); // actually only M[0]=0; is needed 
  L=0;
  for (int i=0; i<N; i++){
    int up=L,down=1,mid;
    int j=0;
    /* binary search */
    while (up>=down){
      mid=(up+down)/2;
      if (X[M[mid]]<X[i]) {j=mid; down=mid+1;}
      else up=mid-1;
    }
    if (j!=0) P[i]=M[j];
    if (j==L or X[M[j+1]]>X[i]){
      M[j+1]=i;
      L=max(L,j+1);}
  }

#if COMMENT
  for (int i=0; i<N; i++) printf("%d ",M[i]);
  printf("\n");
  for (int i=0; i<N; i++) printf("%d ",P[i]);
  printf("\n---------------\n");
#endif
  
  printf("length: %d\n",L);
  stack<int> S;
  int at=M[L];
  while (at!=-1){
    S.push(at);
    at=P[at];}
  while (!S.empty()){
    printf("%d ",X[S.top()]);
    S.pop();}
  printf("\n");
}
      
      
