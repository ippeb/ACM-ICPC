/* 
   Greatest Common Divisor (iterative).
   
   Copyright 2015 Josef Ziegler 
*/

int gcd(int a, int b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}

int main() {
}
