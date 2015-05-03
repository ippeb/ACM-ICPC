/*
  Next permutation.

  Next permutation computes the next lexicographical permutation
  of a given array of integers.

  The main function computes the next permutation until there is no more next
  permutation, i.e. the given integer sequence is sorted in decreasing order
  (also known as snail sort).

  (c) 2015 Josef Ziegler (ippeb24@gmail.com)

*/

#include <cstdio>
#include <algorithm>
#define INF 1000000000
using namespace std;

// returns false if there were was no next permutation
// else returns true
bool next_permutation(int* A, int n) {
  int at=-1;
  for (int i=n-2; i>=0; i--){
    if (A[i]<A[i+1]){
      at=i;
      break;}}
  if (at==-1) return false;
  
  int f=A[at+1],fidx=at+1;
  for (int i=at+1; i<n; i++){
    if (A[i]<=f and A[i]>A[at]) {
      f=A[i];
      fidx=i;}}
  
  int ins=A[at];
  A[at]=f;
  A[fidx]=ins;
  
  // this is essential since the integers in the interval [at+1,l-1] are 
  // sorted in descending order, but need to be sorted in ascending order 
  int diff=n-(at+1);
  for (int i=0; i<diff/2; i++){
    int swap=A[at+1+i];
    A[at+1+i]=A[n-1-i];
    A[n-1-i]=swap;}
  return true;
}


int main(){
  int l;
  scanf("%d", &l);
  int *A = new int[l];
  for (int i = 0; i < l; i++)
    scanf("%d", &A[i]);
  
  while (1){
    for (int i=0; i<l; i++) printf("%d",A[i]);
    printf("\n");    

    if (!next_permutation(A, l)) 
      break;
  }
}

