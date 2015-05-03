/*
  Longest Common Subsequence Length (efficient).

  O(n^2) using memoization.


  char * A;
  char * B;
  int lcs_length(char * AA, char * BB)
  {
  A = AA; B = BB;
  return subproblem(0, 0);
  }
  int subproblem(int i, int j)
  {
  if (A[i] == '\0' || B[j] == '\0') return 0;
  else if (A[i] == B[j]) return 1 + subproblem(i+1, j+1);
  else return max(lcs_length(i+1, j), subproblem(i, j+1));
  }
  
  The problem with the recursive solution is that the same subproblems get 
  called many different times. A subproblem consists of a call to lcs_length, 
  with the arguments being two suffixes of A and B, so there are 
  exactly (m+1)(n+1) possible subproblems (a relatively small number). 
  If there are nearly 2^n recursive calls, some of these subproblems must be 
  being solved over and over.
  The dynamic programming solution is to check whenever we want to solve a 
  subproblem, whether we've already done it before. If so we look up the 
  solution instead of recomputing it. Implemented in the most direct way, we 
  just add some code to our recursive algorithm to do this look up -- this 
  "top down", recursive version of dynamic programming is known as "memoization".
  
  In the LCS problem, subproblems consist of a pair of suffixes of the two 
  input strings. To make it easier to store and look up subproblem solutions, 
  I'll represent these by the starting positions in the strings, rather than 
  (as I wrote it above) character pointers.

  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

char A[1000];
char B[1000];
char L[1000][1000];
int i,j,m;

int subproblem(int i, int j)
{
  if (L[i][j] < 0) {
    if (A[i] == '\0' || B[j] == '\0') L[i][j] = 0;
    else if (A[i] == B[j]) L[i][j] = 1 + subproblem(i+1, j+1);
    else L[i][j] = max(subproblem(i+1, j), subproblem(i, j+1));
  }
  return L[i][j];
}

int lcs_length(char * A, char * B)
{
  /*  allocate storage for L; */
  m=max(strlen(A),strlen(B))+1;
  for (i = 0; i <= m; i++)
    for (j = 0; j <= m; j++)
      L[i][j] = -1;

  return subproblem(0, 0);
}


int main(){
  scanf("%s %s",A,B);
  printf("%d\n",lcs_length(A,B));
}
	 
