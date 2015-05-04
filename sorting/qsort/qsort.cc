/*
  Quicksort.

  Worst case: O(n^2).
  Average case: O(n log n).

  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <iostream>
#include <string>
#define MAX 100000
using namespace std;

int n; /* number of items (integers) to sort */
int C[MAX];

/* function to determine the partitions */
/* partitions the array and returns the middle subscript */
int partition(int A[], int top, int bottom){
  int x=A[top]; /* pivot element = first element */
  int i=top;
  int j=bottom;
  int tmp;
  do {
    while (x>A[j]) j--;
    while (x<A[i]) i++;
    
    if (i<j) {
      tmp=A[i]; /* swap A[i] with A[j] */
      A[i]=A[j];
      A[j]=tmp;}
  } while (i<j);
  return j;
}

  /* sort in descending order */
  void quicksort(int A[], int top, int bottom){ 
    /* top: subscript of beginning of array
     bottom: subscript of end of array */
  int middle;
  if (top<bottom){
    middle=partition(A,top,bottom);
    quicksort(A,top,middle);      // sort first section 
    quicksort(A,middle+1,bottom); // sort second section
  }
}


int main(){
  scanf("%d",&n);
  for (int i=0; i<n; i++) scanf("%d",&C[i]);
  quicksort(C,0,n);
  for (int i=0; i<n; i++) printf("%d\n",C[i]);
}
  
  
