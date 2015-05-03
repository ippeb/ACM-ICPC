/*
  Stack (STL).

  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <stack>
using namespace std;

stack <int> S;

int main(){
  printf("insert numbers, stop with -1\n");
  int m;
  do{
    scanf("%d",&m);
    S.push(m);
  }while (m!=-1);
  printf("number of items: %d\n",S.size());
  printf("insert number of items to pop and print: ");
  scanf("%d",&m);
  int i;
  for (i=0; i<m; i++){
    printf("%d\n",S.top());
    S.pop();}
}
  
