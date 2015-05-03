/* 
   Suffix Array O(n log(n)^2).
   
   What is a suffix tree/trie, what is a suffix array?

   suffix trie/trie:
   
   A trie or a suffix tree is meant to store strings. 
   The number of children of an arbitrary node is equal to the 
   size of the alphabet (of the strings to be stored). Every edge 
   going from the father to its sons is labelled with a different 
   letter of the alphabet. The labels on a path starting from 
   the root and ending in a leaf form a string stored in that tree. 
   Those formed strings are suffixes of our original string A (we 
   consider the string itself also to be a suffix).
   
   suffix array:
   
   Given a string A=a_0,a_1,...,a_n-1, denote by A_i=a_i,a_i+1,...,a_n-1 
   the suffix of A that begins at pos. i.
   By doing a DFS of the trie (consider the nodes in the ascending 
   lexicographic order of the edges linking them to their father) we 
   get the suffixes of A in sorted (ascending) order (e.g. A_1,A_2,A_0,A_3).
   The array which maintains the index of every suffix in the sorted 
   array is called the suffix array. 
   
   Ex. P = (0, 2, 1, 3) for string abac,
   abac = A_0, ac = A_2, bac = A_1, c = A_3
   
   
   *********
   Main idea:
   
   The algorithm is mainly based on maintaining the order of the string's 
   suffixes sorted by their 2^k long prefixes. We shall execute 
   m=ceil(log_2 n) steps, computing the order of the prefixes of length 2^k at 
   the k-th step. It is used an m x n sized matrix. Let's denote by A_i^k the 
   subsequence of A of length 2^k starting at pos. i. The pos. of A_i^k in the 
   sorted array of A_j^k subsequences (j=1,n) is kept in P_(k,i).
   

   see "Suffix arrays - a programming contest approach" for more info.
   *********
   Complexity:
   Using the STL sort function we get O(n log(n)^2).
   

   (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <cstring>
#include <algorithm>  // for STL sort
using namespace std;

struct entry {
  int nr[2];
  int p;
};

bool cmp(struct entry a, struct entry b) {
  if (a.nr[0] == b.nr[0]) 
    return a.nr[1] < b.nr[1];
  return a.nr[0] < b.nr[0];
}

void printstep(int step, entry* L, int** P, int N) {
  printf("L[i].nr[0] ");
  for (int i = 0; i < N; i++) 
    printf("%2d ", L[i].nr[0]);
  printf("\n");

  printf("L[i].nr[1] ");
  for (int i = 0; i < N; i++) 
    printf("%2d ", L[i].nr[1]);
  printf("\n");

  printf("L[i].p     ");
  for (int i = 0; i < N; i++) 
    printf("%2d ", L[i].p);
  printf("\n");

  printf("P[%d][i]    ", step);
  for (int i = 0; i < N; i++) {
    printf("%2d ",P[step][i]);
  }
  printf("\n");
  printf("\n");
}

void printall(char* A, int** P, int N){
  int k = 0;  
  for (k = 0; ((1 << k) >> 1) < N; k++);
  for (int i = 0; i < N; i++) {
    int j;
    for (j = 0; j < N; j++)
      if (i == P[k][j])
	break;
    for (int p = j; p < N; p++)
      printf("%c", A[p]);
    printf("\n");
  }
  printf("\n");
}

void suffix_array(char* A) {
  int N = strlen(A);
  entry* L = new entry[N+2];
  // P[k][i] position of suffix of A that begins
  // at position i of length 2^k
  int logn = 0; // log_2(n)+1
  for (int tmp = N; tmp > 0; tmp /= 2, logn++) ;
  logn++;
  int**  P = new int*[N+2]; // log(n) x n matrix,
    for (int i = 0; i < N; i++) 
      P[i] = new int[logn+2];

  // STEP 0
  for (int i = 0; i < N; i++) 
    P[0][i]=A[i]-'a'; 
  // STEP 1
  for (int stp = 1, cnt = 1; (cnt >> 1) < N; stp++, cnt <<= 1) {
    // stp: step, cnt: 2^(stp-1) if stil < N
    for (int i = 0; i < N; i++) {         // for every element
      L[i].nr[0] = P[stp - 1][i];
      if (i + cnt < N) 
	L[i].nr[1] = P[stp - 1][i + cnt]; // merge those of same length
      else        
	L[i].nr[1] = -1;                  // if it doesn't exceed array border
      L[i].p = i;                         // position
    }
    // step 2
    sort(L, L + N, cmp);
    // step 3
    for (int i = 0; i < N; i++) 
      P[stp][L[i].p] = (i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1])
	               ? P[stp][L[i - 1].p] : i;
    printstep(stp, L, P, N);
  }
  printall(A, P, N);
}
  
int main(){
  char A[100000];
  scanf("%s",A); 

  suffix_array(A);
}
