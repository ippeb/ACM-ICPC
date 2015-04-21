/*
  Prime number generator using Sieve of Erastosthenes.
  
  Sieve of Erastosthenes: go from i=2 to sqrt(n) and for each i mark the 
  multiples of i in a bool array of size n as visited, the unvisited spots are 
  prime numbers (exception: numbers 0 and 1).
  
  Computing all primes <= n takes O(n).

  Can be further optimized by 
  * using char instead bool array saving 256 values
  * using modular arithmetic

  (c) 2015 Josef Ziegler (ippeb24@gmail.com)

*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include "string.h"
#define  N      (1<<20)
#define  SQRTN  (1<<10)
using namespace std;

bool B[N+1]; // mark as visited
int  P[N+1]; // P[i] the ith largest prime number, domain: 0,...,pcnt-1
int  pcnt;
int  n;

void sieve(){
  B[0]=true;
  B[1]=true;
  pcnt=0;
  int sqrtn=sqrt(n)+1;
  for (int i=2; i<=sqrtn; i++)
    if (!B[i]){
      P[pcnt++]=i;
      for (int j=2; (j*i)<=n; j++) B[j*i]=true;
    }
  for (int i=sqrtn+1; i<=n; i++) 
    if (!B[i])
      P[pcnt++]=i;
}

int main(){
  memset(B,0,sizeof B);
  scanf("%d",&n);
  if (n>N) return -1;
  sieve();
  for (int i=0; i<pcnt; i++) printf("%d\n",P[i]);
}
  
