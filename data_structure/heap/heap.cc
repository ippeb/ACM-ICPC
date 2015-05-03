/*
  Heap.

  This program implements a min-heap.
  Implemented using an array, tree structure is guaranteed to be balanced.

  get_min: O(1)
  insert value: O(log n)
  delete_min: O(log n)

  Parent has key larger equal his two children.

            1
         2     3
     4     5 6     7
   8  9  10

  Current node: n.
  Left child: 2*n.
  Right child: 2*n+1.

  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<int> V;

int get_min(vector<int>& A){
  if (A.size() <= 1) return -1; // there is no min
  return A[1];
}

void delete_min(vector<int>& A){
  A[1]=A[A.size()-1];
  int index=1;
  // replace root with node with last index, now "bubble down" 
  while (1){ 
    int left=index*2, right=index*2+1;
    if (left < A.size()){
      if (right < A.size()){ 
	if (A[right] < A[left]) { // there is a left and right node
	  swap(A[right], A[index]);
	  index = rght;
	  continue;
	}
      }
      swap(A[left], A[index]); // there is only a left node or the left node is smaller
      index = left;
    }
    break; // index == A.size()-1
  }
}

void insert(vector<int>& A, int x){
  A.push_back(x);
  int index = A.size()-1;
  
  
int main(){
  
  
}
