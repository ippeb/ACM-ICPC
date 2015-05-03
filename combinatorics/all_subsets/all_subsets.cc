/* constructing all subsets using backtracking */

#include <cstdio>
#define MAXCANDIDATES 10000
using namespace std;

bool finished = false;    /* found all solutions yet? */

bool is_a_solution(int A[], int k, int n){
  return (k==n);
}

void construct_candidates(int A[], int k, int n, int C[], int *ncandidates){
  C[0]=0;
  C[1]=1;
  *ncandidates = 2;}

void process_solution(int A[], int k, int n){
  printf("{");
  for (int i=1; i<=k; i++){
    if (A[i]==1) printf(" %d",i);}
  printf(" }\n");
}


void backtrack(int A[], int k, int n){ // input - any data type possible
  int C[MAXCANDIDATES]; /* candidates for next position */
  int ncandidates;      /* next position candidate count */
  if (is_a_solution(A,k,n))
    process_solution(A,k,n);
  else {
    k++;
    construct_candidates(A,k,n,C,&ncandidates);
    for (int i=0; i<ncandidates; i++){
      A[k]=C[i];
      backtrack(A,k,n);
      if (finished) return; /* terminate early */
    }
  }
}

int main(){
  int n;
  int A[1000];
  scanf("%d",&n);
  backtrack(A,0,n);
}
