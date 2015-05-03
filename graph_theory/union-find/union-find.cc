/*
  Union-Find.

  Union-Find algorithm using path-compression, also known as 
  "weighted quick union with path compression".

  union: O(log* n) n: number of objects, log*: faster than actual log, 
  it is the number of times needed to take the log of a number until reaching 1.
  
  find:  O(log n)
  
  initialization: O(n)

  This algorithm solves the following problem efficiently.
  Problem: you are given a set of objects; you can perform two operations on them
  1) (find)   Are objects i and j in the same set?
  2) (union)  Merge sets containing i and j.

  (c) 2015 Josef Ziegler

*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <complex>
#define MP              make_pair
#define CMNT            1
#define INF             0x3fffffff
#define MM(s,a)         memset((s),(a),sizeof((s)))
using namespace std;

typedef unsigned           uint;
typedef long long int     llint;
typedef pair<int,int>       PII;
typedef pair<double,double> PDD;

int id[100001]; // id[i]: parent of i
int sz[100001]; // sz[i]: count number of elements in the tree rooted at i

void initialize(int *A, int *S, int N){
  for (int i=0; i<N; i++) {
    A[i]=i;
    S[i]=1;}
}

int root(int *A, int i){
  while (i != A[i]){
    // this section is the so-called path-compression 
    A[i] = A[A[i]];
    // end of path-compression
    i = A[i];
    }
  return i;
}

bool find(int *A, int p, int q){
  return root(A,p)==root(A,q);}

void unite(int *A, int *S, int p, int q){
  int i=root(A,p);
  int j=root(A,q);
  if (S[i]<S[j]) {A[i]=j; S[j]+=S[i];}
  else           {A[j]=i; S[i]+=S[j];}
}

int N,M,Q; // N objects, M unites, Q queries (find)

int main(){
  scanf("%d %d %d",&N,&M,&Q);
  initialize(id,sz,N);
  for (int i=0; i<M; i++) {
    int a,b;
    scanf("%d %d",&a,&b);
    unite(id,sz,a,b);}
  for (int i=0; i<Q; i++){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%s\n",find(id,a,b)?"yes":"no");
  }
}
