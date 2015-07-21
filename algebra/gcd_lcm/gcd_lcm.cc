/* 
   Greatest Common Divisor and Least Common Multiple.

   Copyright 2015 Josef Ziegler 
*/

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int lcm(int a, int b) {
  return (a*b) / gcd(a, b);
}

int main() {
}
