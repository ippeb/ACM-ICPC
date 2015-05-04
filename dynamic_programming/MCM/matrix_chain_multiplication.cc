/*
  Matrix Chain Multiplication.

  Output the minimum number of multiplications needed.

  Input
  N (# Matrices)
  N lines with two integers a, b
    the dimensions of the matrices (a x b) that need to be multiplied in 
    the given order

  (c) 2015 Josef Ziegler
  
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#define INF 1000000000
#define COMMENT 0
using namespace std;

int N;
int P[101];
int DP[101][101];
int S[101][101]; /* for extracting the actual sequence */

void recovery(int a, int b){
  if (a-b==0) printf("A%d",a+1);
  else {
    printf("(");
    recovery(a,S[a][b]);
    printf(" x ");
    recovery(S[a][b]+1,b);
    printf(")");
  }
}

int main(){
  scanf("%d",&N);
  for (int i=0; i<N; i++) scanf("%d %d",&P[i],&P[i+1]);
#if COMMENT 
  for (int i=0; i<=N; i++) printf("%d ",P[i]);
  printf("\n----------\n");
#endif 
  
  memset(DP,0,sizeof DP);
  for (int l=2; l<=N; l++){
    for (int i=0; i<=N-l; i++){
      int j=i+l-1;
      DP[i][j]=INF;
      for (int k=i; k<j; k++){
#if COMMENT
	printf("DP[%d][%d] with k=%d\n",i,j,k);
#endif
	int q=DP[i][k]+DP[k+1][j]+P[i]*P[k+1]*P[j+1];
	if (q<DP[i][j]) {
	  DP[i][j]=q;
	  S[i][j]=k;}
      }
    }
  }
#if COMMENT
  printf("--------\n");
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      printf("%8d",DP[i][j]);
    }
    printf("\n");
  }
  printf("\n------ recovery ---\n");
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      printf("%8d",S[i][j]);
    }
    printf("\n");
  }
  printf("\n");
#endif
  
  recovery(0,N-1);
  printf("\n");

  printf("%d\n",DP[0][N-1]);
  return 0;
}
