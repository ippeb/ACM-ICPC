/*
  Mergesort.

  O(n log n).

  (c) 2015 Josef Ziegler
  
*/

#include <cstdio>
#include <iostream>
#include <string>
#define MAX 100000
using namespace std;

void merge(int *A, int *tmp, int top, int mid, int bottom);
void m_sort(int *A, int *tmp, int top, int bottom);

void mergesort(int *A, int *tmp, int array_size){
  m_sort(A,tmp,0,array_size-1);
}


void m_sort(int *A, int *tmp, int lo, int hi){ 
  /* using closed intervals */
  if (lo<hi){
    int mid = (lo+hi) / 2;
    m_sort(A, tmp, lo, mid);
    m_sort(A, tmp, mid+1, hi);
    merge (A, tmp, lo, mid+1, hi);
  }
}



void merge(int *A, int *tmp, int lo, int mid, int hi){ 
  /* A and tmp are sorted arrays */
  int lo_end = mid-1, tmp_pos = lo, num_elements = hi-lo+1;
  
  while ((lo <= lo_end) && (mid <= hi)){
    if (A[lo] <= A[mid]){
      tmp[tmp_pos] = A[lo];
      tmp_pos++;
      lo++;
    }
    else {
      tmp[tmp_pos] = A[mid];
      tmp_pos++;
      mid++;
    }
  }
  
  while (lo <= lo_end){
    tmp[tmp_pos] = A[lo];
    tmp_pos++;
    lo++;
  }
  while (mid <= hi){
    tmp[tmp_pos] = A[mid];
    tmp_pos++;
    mid++;
  }
  
  for (int i=0; i < num_elements; i++){
    A[hi] = tmp[hi];
    hi--;
  }
}




int n, A[MAX],B[MAX];

int main(){
  scanf("%d",&n);
  for (int i=0; i<n; i++) scanf("%d",&A[i]);
  mergesort(A,B,n);
  for (int i=0; i<n; i++) printf("%d\n",A[i]);
}
