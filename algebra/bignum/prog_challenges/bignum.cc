/* 
   High-Precision Arithmetic implemented with Arrays of Digits.

   Adapted from the book "Programming Challenges" by Steven S. Skiena and 
   Miguel A. Revilla, 2003, Springer.

   (c) 2015 Josef Ziegler (ippeb24@gmail.com)

*/

#include "stdio.h"
#include "iostream"

#define MAXDIGITS 100 /* maximum length bignum */
#define PLUS 1        /* positive sign bit */
#define MINUS -1      /* negative sign bit */

typedef struct {
  char digits[MAXDIGITS]; /* represents the number */
  int signbit;            /* PLUS or MINUS */
  int lastdigit;          /* index of high-order digit */
} bignum;

void print_bignum(bignum *N){
  int i;
  if (N->signbit == MINUS) printf("-");
  for (i=N->lastdigit; i>=0; i--)
    printf("%c",'0'+ N->digits[i]);
  printf("\n");}

void initialize_bignum(bignum *A){
  A->lastdigit=0;
  A->signbit=PLUS;
  memset(A->digits,0,MAXDIGITS);}

void zero_justify(bignum *N){
  while ((N->lastdigit > 0) && (N->digits[N->lastdigit] == 0))
    N->lastdigit--;
  if ((N->lastdigit == 0) && (N->digits[0] == 0))
    N->signbit = PLUS;} /* hack to avoid -0 */

void subtract_bignum(bignum *A, bignum *B, bignum *C);
void add_bignum(bignum *A, bignum *B, bignum *C){
  int carry=0; /* carry digit */
  int i;       /* counter */
  initialize_bignum(C);
  
  if (A->signbit == B->signbit) C->signbit = A->signbit; /* addition */
  else {                                             /* subtraction */
    if (A->signbit == MINUS){                     
      A->signbit = PLUS;
      subtract_bignum(B,A,C);
      A->signbit = MINUS;}
    else {
      B->signbit = PLUS;
      subtract_bignum(A,B,C);
      B->signbit = MINUS;}
    return;}

  C->lastdigit = (A->lastdigit > B->lastdigit ? A->lastdigit : B->lastdigit) + 1;
  /* managing last digit of C */
  for (int i=0; i<=C->lastdigit; i++){ /* actual calculation */
    C->digits[i] = (char) (carry+A->digits[i]+B->digits[i]) % 10;
    carry = (carry + A->digits[i] + B->digits[i]) / 10;}
  
  zero_justify(C); /* checks for leading zeros */
}
  
int compare_bignum(bignum *A, bignum *B){ /* A < B ? */
  int i;       /* counter */
  if ((A->signbit == MINUS) && (B->signbit == PLUS))  return(PLUS);/* signbits */
  if ((A->signbit == PLUS)  && (B->signbit == MINUS)) return(MINUS);
  
  if (B->lastdigit > A->lastdigit) return(PLUS  * A->signbit); /* different */
  if (B->lastdigit < A->lastdigit) return(MINUS * A->signbit); /* length    */
  
  for (i = A->lastdigit; i>=0; i--){ /* same length */
    if (A->digits[i] > B->digits[i]) return (MINUS * A->signbit);
    if (A->digits[i] < B->digits[i]) return (PLUS * A->signbit);}
  
  return(0);}

void subtract_bignum(bignum *A, bignum *B, bignum *C){
  int borrow=0; /* anything borrowed? */
  int v;        /* placeholder digit  */
  int i;        /* counter            */
  initialize_bignum(C);
  
  if ((A->signbit == MINUS) || (B->signbit == MINUS)){
    B->signbit = -1 * B->signbit;
    add_bignum(A,B,C);
    B->signbit = -1 * B->signbit;
    return;}
  
  if (compare_bignum(A,B) == PLUS){ // A < B
    subtract_bignum(B,A,C);
      C->signbit = MINUS;
      return;}

    C->lastdigit = A->lastdigit > B->lastdigit ? A->lastdigit : B->lastdigit;
    
    for (i=0; i<=(C->lastdigit); i++){
      v = (A->digits[i] - borrow - B->digits[i]);
      if (A->digits[i] > 0) borrow = 0;
      if (v < 0) {
	v = v + 10;
	borrow = 1;}
      C->digits[i] = (char) v % 10;
    }
    zero_justify(C);
}

void digit_shift(bignum *N, int d){ /* multiply n by 10^d */
  int i; /* counter */
  if ((N->lastdigit == 0) && (N->digits[0] == 0)) return; /* case N->digits = 0 */
  for (i=N->lastdigit; i>=0; i--) N->digits[i+d] = N->digits[i];
  for (i=0; i<d; i++) N->digits[i] = 0;
  N->lastdigit = N->lastdigit + d;}

void multiply_bignum(bignum *A, bignum *B, bignum *C){
  bignum row;           /* respresent shifted row */
  bignum tmp;           /* placeholder bignum */
  int i,j;              /* counter */
  initialize_bignum(C);

  row = *A;
  for (i=0; i<=B->lastdigit; i++){
    for (j=1; j<=B->digits[i]; j++){
      add_bignum(C,&row,&tmp);
      *C = tmp;}
  digit_shift(&row,1);
  }
  C->signbit = A->signbit * B->signbit;
  zero_justify(C);
}

void division_bignum(bignum *A, bignum *B, bignum *C){
  bignum row;           /* represent shifted row */
  bignum tmp;           /* placeholder bignum */
  int asign=A->signbit; /* temporary signs    */
  int bsign=B->signbit;
  int i,j;              /* counters */
  initialize_bignum(C);
  C->signbit = A->signbit * B->signbit;
  A->signbit = PLUS;
  B->signbit = PLUS;
  initialize_bignum(&row);
  initialize_bignum(&tmp);
  C->lastdigit = A->lastdigit;
  
  for (i=A->lastdigit; i>=0; i--){
    digit_shift(&row,1);
    row.digits[0] = A->digits[i];
    C->digits[i] = 0;
    while (compare_bignum(&row,B) != PLUS){
      C->digits[i]++;
      subtract_bignum(&row,B,&tmp);
      row = tmp;}
  }
  zero_justify(C);
  A->signbit = asign;
  B->signbit = bsign;
}

void int_to_bignum(int s, bignum *N){
  int i;         /* counter */
  int t;         /* int to work with */
  if (s >= 0) N->signbit = PLUS;
  else N->signbit = MINUS;
  
  memset(N->digits,0,sizeof N->digits);
  N->lastdigit=-1;
  t = abs(s);
  while (t>0) { 
    N->lastdigit++;
    N->digits[N->lastdigit] = t % 10;
    t = t / 10;}
  if (s == 0) N->lastdigit=0;
}

int main(){

}
