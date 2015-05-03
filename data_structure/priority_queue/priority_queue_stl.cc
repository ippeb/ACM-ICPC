/* 
   Priority Queue (STL).

   (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct cmp{
  bool operator()(int a, int b){
    return a<b;}};
// largest element ontop (max-heap)

priority_queue<int,vector<int>,cmp> P;

int main(){
  printf("insert some values, enter -1 to quit\n");
  int m;
  do{
    scanf("%d",&m);
    P.push(m);
  } while (m!=-1);
  printf("number of elements: %d\n",P.size());
  printf("how many elements do you want to pop: ");
  scanf("%d",&m);
  printf("\n");
  for (int i=0; i<m; i++){
    printf("%d\n",P.top());
    P.pop();}
}
  
