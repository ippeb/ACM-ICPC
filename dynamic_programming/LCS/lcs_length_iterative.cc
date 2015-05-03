/*
  Longest Common Subsequence Length (iterative).

  Bottom up, iterative, very efficient, O(n^2).
  This is iterative (because it uses nested loops instead of recursion) or 
  bottom up (because the order we fill in the array is from smaller simpler 
  subproblems to bigger more complicated ones).

  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include "string.h"
using namespace std;

char A[1000];
char B[1000];
int L[1000][1000];
int i,j,m,n;

int lcs_length(char * A, char * B)
{
  m=strlen(A);
  n=strlen(B);
  /*  allocate storage for array L; */
  for (i = m; i >= 0; i--)
    for (j = n; j >= 0; j--)
      {
          if (A[i] == '\0' || B[j] == '\0') L[i][j] = 0;
          else if (A[i] == B[j]) L[i][j] = 1 + L[i+1][j+1];
          else L[i][j] = max(L[i+1][j], L[i][j+1]);
      }
  return L[0][0];
}

int main(){
  memset(L,-1,sizeof L);
  scanf("%s %s",A,B); 
  printf("solution:%d\n\n",lcs_length(A,B));
  m=strlen(A);
    n=strlen(B);
  printf("%3c",' ');
  for (i = 0; i <= m; i++) printf("%3c",A[i]);
  printf("\n");
  for (i = 0; i <= n; i++){
    printf("%3c",B[i]);
    for (j = 0; j <= m; j++)
      printf("%3d",L[j][i]);
    printf("\n");
  }


}

