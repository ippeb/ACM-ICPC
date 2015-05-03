/*
  Next permutation (STL).

  Next permutation computes the next lexicographical permutation
  of a given array of integers using STL's next_permutation.

  The main function computes the next permutation until there is no more next
  permutation, i.e. the given integer sequence is sorted in decreasing order
  (also known as snail sort).

  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int l;
  scanf("%d", &l);
  int *A = new int[l];
  for (int i = 0; i < l; i++)
    scanf("%d", &A[i]);
  
  do{
    for (int i=0; i<l; i++) printf("%d",A[i]);
    printf("\n");
  } while (next_permutation(A,A+l));
}
