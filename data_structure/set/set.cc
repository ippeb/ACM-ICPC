/* 
   Set (STL).
  
   (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <set>
using namespace std;

set<int> S;
set<int>::iterator iter;

int main(){
  printf("insert some numbers, stop with -1\n");
  int m;
  while(1){
    fscanf(stdin,"%d",&m);
    S.insert(m);
    if (m==-1)
      break;
  }
  printf("number of distinct elements: %d\n",S.size());
  for (iter=S.begin(); iter!=S.end(); iter++)
    printf("%d\n",*iter);
  printf("element to erase: ");
  putchar(10);
  scanf("%d",&m);
  if (S.count(m))
    S.erase(S.find(m));
  else
    printf("not found");
  putchar(10);
  for (iter=S.begin(); iter!=S.end(); iter++)
    printf("%d\n",*iter);
}
