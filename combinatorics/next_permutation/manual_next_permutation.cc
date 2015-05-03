/* using next permutation algorithm, 
   (snail sort)
   prints all permutations of an integer sequence in lexicographically ascending order
   starting with the permutation given
*/

#include <cstdio>
#include <algorithm>
#define INF 1000000000
using namespace std;

int main(){
  int A[]={1,2,3,1,3,1};
  int l=sizeof(A)/sizeof(int);
  
  while (1){
    for (int i=0; i<l; i++) printf("%d",A[i]);
    printf("\n");    

    int at=-1;
    for (int i=l-2; i>=0; i--){
      if (A[i]<A[i+1]){
	at=i;
	break;}}
    if (at==-1) break;
    
    int f=A[at+1],fidx=at+1;
    for (int i=at+1; i<l; i++){
      if (A[i]<=f and A[i]>A[at]) {
	f=A[i];
	fidx=i;}}
    
    int ins=A[at];
    A[at]=f;
    A[fidx]=ins;


    // this is essential since the integers in the interval [at+1,l-1] are sorted in descending order, but need to be sorted in ascending order 
    int diff=l-(at+1);
    for (int i=0; i<diff/2; i++){
      int swap=A[at+1+i];
      A[at+1+i]=A[l-1-i];
      A[l-1-i]=swap;}
  }
}

