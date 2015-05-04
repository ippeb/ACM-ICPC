/*
  Maximum Empty Rectangle (MER).

  O(M*N) time, O(M*N) memory (could be optimized to O(M)).

  You are given a 2D matrix (M rows, N columns) of boolean values, '0' and '1'.
  Find the largest (most elements) rectangular subarray containing only ones.

  Input:
  M,N
  MxN matrix

  (c) 2015 Josef Ziegler
  
*/

#include <cstdio>
#include <stack>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#define MP make_pair
#define COMMENT 0
#define MAX 10001
using namespace std;

typedef pair<int,int> PII;
int M,N;
char A[MAX+1][MAX+1];
int  c[MAX+1][MAX+1];
int best;
PII a1,a2;

int main(){
  /* INITIALIZE */
  memset(c,0,sizeof c);
  
  /* INPUT */
  scanf("%d %d",&M,&N);
  for (int i=0; i<M; i++) scanf("%s",&A[i]);
  
#if COMMENT
  printf("INPUT\n");
  for (int i=0; i<M; i++){
    for (int j=0; j<N; j++)
      printf("%c",A[i][j]);
    printf("\n");
  }
  printf("\n");
#endif
  
  /* COMPUTE CACHE */
  for (int i=M-1; i>=0; i--)
    for (int j=N-1; j>=0; j--)
      if (A[i][j]-'0') c[i][j]=c[i][j+1]+1;
      else c[i][j]=0;
  
#if COMMENT 
  printf("cache\n");
  for (int i=0; i<M; i++){
    printf("%3d: ",i+1);
    for (int j=0; j<N; j++)
      printf("%3d",c[i][j]);
    printf("\n");
  }
  printf("\n");
#endif

  M++; /* because we add an empty row at the bottom */
  best=0;
  stack<PII> S;
  S.push(MP(-42,-42));
  for (int j=0; j<N; j++){
    for (int i=0; i<M; i++){
      if (c[i][j]==S.top().first) ;
      else if (c[i][j]>S.top().first) S.push(MP(c[i][j],i));
      else {
	int last;
	while (c[i][j]<S.top().first) {
	  int tmp=(i-S.top().second)*S.top().first;
	  if (tmp>best){
	    best=tmp;
	    a1=MP(S.top().second,j); // y and x
	    a2=MP(i-1,j+S.top().first-1);
	  }
	  last=S.top().second;
	  S.pop();
	}
	if (c[i][j]>0) S.push(MP(c[i][j],last));
      }
    }
  }
  printf("%d at [x1,y1][x2,y2] (%d, %d) (%d, %d)\n",best,a1.second+1,a1.first+1,a2.second+1,a2.first+1);
#if COMMENT
  printf("\n");
  for (int i=a1.first; i<=a2.first; i++){
    for (int j=a1.second; j<=a2.second; j++){
      printf("%c",A[i][j]);
    }
    printf("\n");
  }
#endif
  return 0;
}
