/*
  Knuth Morris Pratt (String Search).

  This program demonstrates knuth morris pratt's string search algorithm 
  O(m+n)=O(n). 
  n:= length of the text.
  m:= length of the pattern (m<=n).
  
  Key idea: provided the values b[0],...,b[i] (entry b[i] contains the width 
  of the widest border of the prefix of length i of the pattern (i=0..m), are 
  already known, the value of b[i+1] is computed by checking if aborder of the 
  prefix p0...pi-1 can be extended by symbol pi.

  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#define MAX 10000
using namespace std;

char P[MAX],T[MAX];
int m,n,b[MAX+1];

void kmpPreprocess(){
  int j=0;
  b[0]=-1;
  b[1]=0;
  for (int i=1; i<m; i++){
    while (j>=0 and P[i]!=P[j]) j=b[j];
    j++;
    b[i+1]=j;
  }
}

void kmpSearch(){
  int j=0;
  for (int i=0; i<n; i++){
    while (j>=0 and T[i]!=P[j]) j=b[j];
    j++;
    if (j==m){
      printf("%d\n",i+1-j);
      j=b[j];
    }
  }
}

int main(){
  scanf("%s %s",&T,&P);
  m=strlen(P);
  n=strlen(T);
  kmpPreprocess();
  kmpSearch();
}
  
