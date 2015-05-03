/* 
   Subsequence Checker.

   Is string a (pattern) a subsequence of string b (text)? 

   (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <iostream>
#define FALSE 0
#define TRUE 1
using namespace std;

int subseq(char * P, char * T)
{
  while (*T != '\0')
    if (*P == *T++ && *++P == '\0')
      return TRUE;
  return FALSE;
}

int main(){
  char a[1000],b[1000];
  scanf("%s %s",&a,&b);
  printf("%d\n",subseq(a,b));
}
