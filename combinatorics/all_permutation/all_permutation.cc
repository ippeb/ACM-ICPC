/* constructing all permutations using backtracking */

#include <cstdio>
#include <string>
#define MAXCANDIDATES 10000
#define MAXN          10000
using namespace std;

bool is_solution(int A[], int k, int n){
  return(k==n);
}

void process_solution(int A[], int k, int n){
  for(int i=1; i<=k; i++) printf(" %d",A[i]);
  printf("\n");
}

void construct_candidates(int A[], int k, int n, int C[], int *ncandidates){
  bool in_perm[MAXN];
  memset(in_perm,0,MAXN);
  for (int i=1; i<k; i++) in_perm[A[i]]=true;
  *ncandidates = 0;
  for (int i=1; i<=n; i++)
    if (in_perm[i] == false){
      C[*ncandidates]=i;
      *ncandidates=*ncandidates+1;
    }
}

void backtrack(int A[], int k, int n){
  int C[MAXCANDIDATES];
  int ncandidates;
  if (is_solution(A,k,n))
    process_solution(A,k,n);
  else{
    k++;
    construct_candidates(A,k,n,C,&ncandidates);
    for (int i=0; i<ncandidates; i++){
      A[k]=C[i];
      backtrack(A,k,n);
    }
  }
}

int main(){
  int A[MAXN];
  int n;
  scanf("%d",&n);
  backtrack(A,0,n);
}
