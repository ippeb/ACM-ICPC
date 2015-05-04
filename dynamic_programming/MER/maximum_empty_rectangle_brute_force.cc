/*
  Maximum Empty Rectangle (MER), brute force.

  O(M^2*N^2) time, O(M*N) memory. 
  A somewhat "smarter" brute force implementation.

  You are given a 2D matrix (M rows, N columns) of boolean values, '0' and '1'.
  Find the largest (most elements) rectangular subarray containing only ones.

  Input:
  M,N
  MxN matrix

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
#include "string.h"
#define MP make_pair
#define COMMENT 0
#define MAX 1000+2
using namespace std;

typedef unsigned uint;
typedef long long int llint;
typedef pair<int,int> PII;

int S[MAX][MAX],M,N,best;
char A[MAX][MAX];
PII a1,a2;

// indexing 1..N (inclusive)

int main(){
  /* INPUT */
  scanf("%d %d",&M,&N);
  for (int i=1; i<=M; i++) scanf("%s",&A[i][1]);

#if COMMENT
  printf("INPUT\n");
  printf("  ");
  for (int j=1; j<=N; j++) printf("%d",j%10);
  printf("\n");
  for (int i=1; i<=M; i++){
    printf("%d ",i%10);
    for (int j=1; j<=N; j++){
      printf("%1d",A[i][j]-'0');
    }
    printf("\n");
  }
  printf("\n");
#endif 
  /* INITIALIZE */
  memset(S,0,sizeof S);

  /* SUM MATRIX */
  for (int i=1; i<=M; i++)
    for (int j=1; j<=N; j++)
      S[i][j]=A[i][j]-'0'+S[i-1][j]+S[i][j-1]-S[i-1][j-1];
  
#if COMMENT
  printf("SUM MATRIX\n");
  for (int i=1; i<=M; i++){
    for (int j=1; j<=N; j++){
      printf("%4d",S[i][j]);
    }
    printf("\n");
  }
  printf("\n");
#endif
  
  /* ALL POSITIONS */
  best=0;
  for (int i=0; i<=M; i++)
    for (int j=0; j<=N; j++)
      for (int k=i+1; k<=M; k++)
	for (int l=j+1; l<=N; l++){
	  int tmp=S[k][l]+S[i][j]-S[k][j]-S[i][l];
	  if (tmp==(k-i)*(l-j))
	    if (tmp>best){
	      best=tmp;
	      a1=MP(i+1,j+1); // inclusive +1
	      a2=MP(k,l);}
	}
  
  printf("%d at [x1,y1][x2,y2] (%d, %d) (%d, %d)\n",best,a1.second,a1.first,a2.second,a2.first);
  
#if COMMENT
  for (int i=a1.first; i<=a2.first; i++){
    for (int j=a1.second; j<=a2.second; j++)
      printf("%c",A[i][j]);
    printf("\n");
  }
#endif
}

	  
	  
	  
	  
	  
