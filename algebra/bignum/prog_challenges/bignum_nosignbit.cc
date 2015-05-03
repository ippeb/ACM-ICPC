/*
  High-Precision Arithmetic in C++ implemented with Arrays of Digits.

  Adapted from the book "Programming Challenges" by Steven S. Skiena and 
  Miguel A. Revilla, 2003, Springer.
   
  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
#define MAXDIGITS 1000 /* maximum length bignum */

typedef struct {
  char D[MAXDIGITS]; /* represents the number (least significant to most significant) */
  int  ld;           /* index of high-order digit */
} bignum;

void print_bignum(bignum &N){
  for (int i=N.ld; i>=0; i--) printf("%c",'0'+ N.D[i]);
  printf("\n");
}

void initialize_bignum(bignum &A){
  A.ld=0;
  memset(A.D,0,MAXDIGITS);
}

void zero_justify(bignum &N){
  while ((N.ld > 0) && (N.D[N.ld]==0)) N.ld--;
}

void subtract_bignum(bignum &A, bignum &B, bignum &C);

void add_bignum(bignum &A, bignum &B, bignum &C){
  int carry=0; /* carry digit */
  initialize_bignum(C);
  C.ld=max(A.ld,B.ld)+1;
  /* managing last digit of C */
  for (int i=0; i<=C.ld; i++){ /* actual calculation */
    C.D[i] = (char) (carry+A.D[i]+B.D[i])%10;
    carry = (carry + A.D[i] + B.D[i])/10;}
  zero_justify(C); /* checks for leading zeros */
}

int compare_bignum(bignum &A, bignum &B){ /* A < B ? */
  if (B.ld > A.ld) return 1; /* different */
  if (B.ld < A.ld) return -1; /* length    */
  for (int i=A.ld; i>=0; i--){ /* same length */
    if (A.D[i] < B.D[i]) return 1;
    if (A.D[i] > B.D[i]) return -1;
  }
  return 0;
}

void subtract_bignum(bignum &A, bignum &B, bignum &C){
  int borrow=0; /* anything borrowed? */
  int v;        /* placeholder digit  */
  initialize_bignum(C);
  C.ld=max(A.ld,B.ld);
  for (int i=0; i<=C.ld; i++){
    v = A.D[i]-borrow-B.D[i];
    if (A.D[i] > 0) borrow = 0;
    if (v < 0) {
      v+=10;
      borrow = 1;}
    C.D[i]=(char)v%10;
  }
  zero_justify(C);
}

void digit_shift(bignum &N, int d){ /* multiply n by 10^d */
  if ((N.ld == 0) && (N.D[0] == 0)) return; /* case N->digits = 0 */
  for (int i=N.ld; i>=0; i--) N.D[i+d] = N.D[i];
  for (int i=0; i<d; i++) N.D[i] = 0;
  N.ld = N.ld+d;
}

void multiply_bignum(bignum &A, bignum &B, bignum &C){ // primary-school method
  bignum row;           /* respresent shifted row */
  bignum tmp;           /* placeholder bignum */
  initialize_bignum(C);
  row = A;
  for (int i=0; i<=B.ld; i++){
    for (int j=1; j<=B.D[i]; j++){
      add_bignum(C,row,tmp);
      C = tmp;}
    digit_shift(row,1);
  }
  zero_justify(C);
}

void division_bignum(bignum &A, bignum &B, bignum &C){
  bignum row;           /* represent shifted row */
  bignum tmp;           /* placeholder bignum */
  initialize_bignum(C);
  initialize_bignum(row);
  initialize_bignum(tmp);
  C.ld=A.ld;
  for (int i=A.ld; i>=0; i--){
    digit_shift(row,1);
    row.D[0] = A.D[i];
    C.D[i] = 0;
    while (compare_bignum(row,B) != 1){
      C.D[i]++;
      subtract_bignum(row,B,tmp);
      row = tmp;}
  }
  zero_justify(C);
}

void int_to_bignum(int s, bignum &N){
  int i;         /* counter */
  int t=abs(s);  /* int to work with */
  memset(N.D,0,sizeof N.D);
  N.ld=-1;
  while (t>0) { 
    N.ld++;
    N.D[N.ld]=t%10;
    t/=10;}
  if (s==0) N.ld=0;
}

int main(){
  
}
