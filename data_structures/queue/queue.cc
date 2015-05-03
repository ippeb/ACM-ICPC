/* 
   Queue (STL).
   
   Using STL queue.
   
   (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <queue>
using namespace std;

queue <int> Q;

int main(){  
  printf("stop by inserting -1 at the end\n");
  printf("insert:\n");
  int m;
  do{
    scanf("%d",&m);
    Q.push(m);
  }while(m!=-1);
  printf("number of elements (including -1): %d\n",Q.size());
  printf("first and last element: %d, %d\n",Q.front(), Q.back());
  printf("remove and print number of elements:");
  int x,i;
  scanf("%d",&x);
  for (i=0;i<x;i++){
    printf("%d\n",Q.front());
    Q.pop();}
}
