/* 
   Greatest Common Divisor and Least Common Multiple.

   (c) 2015 Josef Ziegler (ippeb24@gmail.com)
   
*/

#include "stdio.h"
using namespace std;

int gcd(int a, int b){
  if (b==0) return a;
  gcd(b, a%b);
}

int lcm(int a, int b){
  return (a*b) / gcd(a,b);
}

int main(){
  int a, b;
  while (1){
    scanf("%d",&a);
    scanf("%d",&b);
    printf("gcd(%d,%d)=%d\n",a,b,gcd(a,b));
    printf("lcd(%d,%d)=%d\n",a,b,lcm(a,b));
  }
}
