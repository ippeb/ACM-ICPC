/*
  Extendend GCD, Linear Congruence.

  Computes gcd(p, q) and x, y such that p * x + q * y = gcd(p, q),
  x, y, p, q are integers.

  (c) 2015 Josef Ziegler (ippeb24@gmail.com)

*/

#include <cstdio>
#include <cmath>
using namespace std;

int gcd(int p, int q, int& x, int& y){
  int x1,y1; /* previous coefficients */
  int g;     /* value of gcd(p,q)     */
  if (q>p) return (gcd(q, p, y, x));
  if (q==0){
    x = 1;
    y = 0;
    return(p);}
  g = gcd(q, p%q, x1, y1);
  x = y1;
  y = x1 - floor(p/q)*y1;
  return g;
}

int main(){
  int p, q, x, y, g, tmp;
  while (1){
    scanf("%d",&p);
    scanf("%d",&q);
    if (p<q){
      tmp = p;
      p = q;
      q = tmp;}
    g = gcd(p, q, x, y);
    printf("%d * %d + %d * %d = %d\n",p,x,q,y,g);
  }
}
  
