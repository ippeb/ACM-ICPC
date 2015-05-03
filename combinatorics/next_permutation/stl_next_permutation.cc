#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int A[]={1,2,3,1,3,1};
  int l=sizeof(A)/sizeof(int);
  
  do{
    for (int i=0; i<l; i++) printf("%d",A[i]);
    printf("\n");
  } while (next_permutation(A,A+l));
}
