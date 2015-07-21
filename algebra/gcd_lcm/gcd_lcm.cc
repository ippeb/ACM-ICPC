/* 
   Greatest Common Divisor and Least Common Multiple.

   (c) 2015 Josef Ziegler
   
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
