/*
  Range Minimum Query using Sparse Tables.

  Determines the (position of) the largest value in i..j of an ordered array 
  of numbers.
  
  O(nlogn) preprocessing time.
  O(1) for each query.

  Input:
  n q (number of values, number of queries)
  n times v_i
  q times a_i b_i

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
#define COMMENT 0
#define MAXN 100001
using namespace std;

typedef unsigned uint;
typedef long long int llint;
typedef pair<int,int> PII;

int A[MAXN];
int M[MAXN][66]; 
int n,q;

int l2(int x){ // round down
  int cnt=0;
  while (x>1){
    cnt++;
    x>>=1;
  }
  return cnt;
}

int RMQ(int a, int b){
  int k=l2(b-a+1);
  if (A[M[a][k]]>A[M[b-(1<<k)+1][k]]) {
    return M[a][k];
  }
  return M[b-(1<<k)+1][k];
}

int main(){
  scanf("%d",&n);
  scanf("%d",&q);
  for (int i=0; i<n; i++) scanf("%d",&A[i]);
  
  // RMQ preprocessing
    for (int i=0; i<n; i++)
      M[i][0]=i;
    for (int j=1; (1<<j)-1 < n; j++)
      for (int i=0; i+(1<<j)-1 < n; i++)
	if (A[M[i][j-1]]>A[M[i+(1<<(j-1))][j-1]])
	  M[i][j]=M[i][j-1];
	else 
	  M[i][j]=M[i+(1<<(j-1))][j-1];
    
#if COMMENT
    printf("\nRMQ\n");
    for (int i=0; i<n; i++){
      printf("at %d: ",i);
      for (int j=0; j<l2(n); j++){
	printf("(%d) %d  ",1<<j,M[i][j]);
      }
      printf("\n");
    }
    printf("\n");
#endif

    for (int i=0; i<q; i++){
      int a,b,sol;
      scanf("%d %d",&a,&b);
      printf("%d\n",A[RMQ(a,b)]);
    }
}
