/* 
   Greatest Common Divisor (iterative).
   
   (c) 2015 Josef Ziegler

*/

#include "stdio.h"
using namespace std;

int gcd(int a, int b) {
  while(b) b ^= a ^= b ^= a %= b;
  return a;
}

int main(){
  int a, b;
  while (1){
    scanf("%d",&a);
    scanf("%d",&b);
    printf("gcd(%d,%d)=%d\n",a,b,gcd(a,b));
  }
}
