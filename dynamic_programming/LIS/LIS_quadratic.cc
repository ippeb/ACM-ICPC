/* 
   Longest (strictly) Increasing Subsequence O(n^2).

   (c) 2015 Josef Ziegler
  
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <stack>
#define COMMENT 0
using namespace std;

int N,A[10001]; /* length of the sequence and sequence */
int DP[10001];
int pre[10001];

int main(){
  scanf("%d",&N); 
  for (int i=0; i<N; i++) scanf("%d",&A[i]);
#if COMMENT 
  for (int i=0; i<N; i++) printf("%d ",A[i]);
  printf("\n");
#endif
  
  memset(pre,-1,sizeof pre);
  for (int i=0; i<N; i++) DP[i]=1;
  for (int i=1; i<N; i++)
    for (int j=0; j<i; j++)
      if (A[j]<A[i] and DP[j]>=DP[i]){
	DP[i]=DP[j]+1;
	pre[i]=j;}
  
  int best=0;
  for (int i=0; i<N; i++) best=max(best,DP[i]);

#if COMMENT 
  printf("----------\n");
  printf("DP\n");
  for (int i=0; i<N; i++) printf("%d ",DP[i]);
  printf("\npredecessor\n");
  for (int i=0; i<N; i++) printf("%d ",pre[i]);
  printf("\n----------\n");
#endif 
  
  printf("length: %d\n",best);
  int at;
  for (int i=0; i<N; i++) if (DP[i]==best) at=i;
  
  stack<int> S;
  do {
      S.push(at);
      at=pre[at];
    } while (at!=-1);

  while (!S.empty()) {
    printf("%d ",A[S.top()]);
    S.pop();}
  
  return 0;
}
