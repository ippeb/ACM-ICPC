/*
  Binary Indexed Tree (Fenwick Tree).

  This data structure solves the following problem efficiently:
  Problem: in total n boxes
    query 1) Add x marbles to box i.
    query 2) Sum marbles from box k to box l.

  But query types take O(log n) using a binary indexed tree.

  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <iostream>
#include "string.h"
#define  MAXN 100000
using namespace std;

int MaxVal;     /* maximum value with a non-zero frequency */
int F[MAXN];    /* frequency of value with index i (1<= i <= MaxVal) */
int C[MAXN];    /* cumulative frequency for index i (F[1] + ... + F[i]) */
int T[MAXN];    /* sum of frequencies stored in BIT with index i from ( i-2^r+1 ) to i
                   r := index of the last non-zero digit
		*/
/* In the following I will use "(idx & -idx)" to isolate the last non-zero digit of idx */

/* read cumulative frequency */
int read(int idx){
  int sum=0;
  while (idx>0){
    sum+=T[idx];
    idx-=(idx & -idx);
  }
  return sum;
}

/* change frequency and update T */
void update(int idx, int val){
  while (idx <= MaxVal){
    T[idx]+=val;
    idx+=(idx & -idx);
  }
}

/* read the actual frequency at a position */
/* easy method: return read(idx)-read(idx-1) */
int readSingle(int idx){
  int sum=T[idx];        /* sum will be decreased */
  if (idx > 0){             /* special case */
    int z=idx-(idx & -idx); /* make z first */
    idx--;                  /* idx is used as y (predecessor of idx) */
    while (idx != z){       /* at some iteration idx (y) will become z */
      sum -= T[idx];     /* subtract T frequency which is between y and "the same path" */
      idx -= (idx & -idx);
    }
  }
  return sum;
}

      
int main(){
  memset(F,0,sizeof F);  memset(C,0,sizeof C);  memset(T,0,sizeof T);

  scanf("%d",&MaxVal);
  for (int i=1; i<=100; i++) update(i,i);
  printf("Ready\n");

  while (1){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",read(b)-read(a));
  }
}
