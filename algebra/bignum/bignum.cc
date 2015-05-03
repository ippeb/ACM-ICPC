/*
  Bignums efficient.
  
  * base conversion (base 10^BASE10)
  * bignum multiplication
  * bignum addition
  * bignum subtraction (for positive results)
  * bignum comparison
  * bignum square root (using binary search)

  (c) 2015 Josef Ziegler

*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <complex>
#define MP              make_pair
#define CMNT            0
// your base: 10^BASE10; in order to use multiplication the square of your 
// chosen base must fit in a long long; maximum: 18
#define BASE10 9 
// in base 10^BASE10, effective number of digits: BASE10*DIGITS 
#define DIGITS 12 
using namespace std;

typedef unsigned           uint;
typedef long long int     llint;
typedef pair<int,int>       PII;
typedef pair<double,double> PDD;

struct bignum{
  llint N[DIGITS]; // in base 10^BASE10
  int   last;
};

llint POW10[20];
// precompute powers of 10
void precomp_pow10(){ 
  POW10[0]=1;
  for (int i=1; i<19; i++) POW10[i]=POW10[i-1]*10;
}

// omit leading zeros
void zerojustify(bignum& A){
  while (A.last>1 && A.N[A.last-1]==0) A.last--;
}

// initialize bignum
void init(bignum& A){
  A.last=1;
  memset(A.N,0,sizeof A.N);
}

// bignum assignment
void assign(bignum& A, bignum& B){ // A:=B
  A.last=B.last;
  for (int i=0; i<B.last; i++) A.N[i]=B.N[i];
  for (int i=B.last; i<DIGITS; i++) A.N[i]=0;
}

// print bignum 
void print(bignum& A, bool newline=true){
  printf("%lld",A.N[A.last-1]);
  for (int i=A.last-2; i>=0; i--)
    for (int j=BASE10-1; j>=0; j--)
      printf("%lld",(A.N[i]/POW10[j])%10);
  if (newline) printf("\n");
	
}

// convert integer saved in char string to bignum (base 10^BASE10)
void base(bignum& A, char* Q){ 
  // manipulate input string such that chars with lowest index are least significant digits 
  char S[DIGITS*BASE10];
  int s=strlen(Q);
  for (int i=0; i<s; i++) S[i]=Q[i]-'0';
  for (int i=0; i<s/2; i++){
    char tmp=S[i];
    S[i]=S[s-1-i];
    S[s-1-i]=tmp;
  }
	
  // base conversion
  init(A);
  A.last=((s-1)/BASE10)+1;
  for (int i=0; i<A.last; i++){
    llint tmp=0;
    for (int j=0; j<BASE10 && (j+i*BASE10)<s; j++) tmp+=(llint)S[j+i*BASE10]*POW10[j];
    A.N[i]=tmp;
  }
}


// bignum addition
void add(bignum& A, bignum& B, bignum& C, llint x=1){ // C=A+B*x
  bignum sol;
  init(sol);
  sol.last=max(A.last,B.last)+1;
  llint tmp,add=0;
  for (int i=0; i<sol.last; i++) {
    tmp=A.N[i]+B.N[i]*x+add;
    sol.N[i]=tmp%POW10[BASE10];
    add=tmp/POW10[BASE10];
  }
  zerojustify(sol);
  assign(C,sol);
}

// bignum subtraction only for positive results (A>B)
void sub(bignum& A, bignum& B, bignum& C){ // C=A-B
  bignum sol;
  init(sol);
  sol.last=max(A.last,B.last);
  llint tmp,borrow=0;
  for (int i=0; i<sol.last; i++){
    tmp=(A.N[i]-B.N[i]-borrow);
    sol.N[i]=(tmp+POW10[BASE10])%POW10[BASE10];
    if (tmp<0) borrow=1;
    else borrow=0;
  }
  zerojustify(sol);
  assign(C,sol);
}


// digit shift by base BASE10
void shift(bignum& A, int n){
  for (int i=A.last-1; i>=0; i--) A.N[i+n]=A.N[i];
  for (int i=n-1; i>=0; i--) A.N[i]=0;
  A.last+=n;
}

// bignum multiplication
void mult(bignum& A, bignum& B, bignum& C){
  bignum tmp,sol;
  init(sol);
  for (int i=0; i<B.last; i++){
    if (B.N[i]==0) continue;
    init(tmp);
    add(tmp,A,tmp,B.N[i]);
    shift(tmp,i);
    add(sol,tmp,sol);
  }
  zerojustify(sol);
  assign(C,sol);
}   

// digit shift by 10
void shift10(bignum& A, int n){
  char S[BASE10*DIGITS];
  S[0]='1';
  for (int i=1; i<=n; i++) S[i]='0';
  S[n+1]=0;
  bignum B;
  base(B,S);
  mult(A,B,A);
}

// bignum comparison
int comp(bignum& A, bignum& B){ // return value: -1: A<B, 0: A==B, 1: A>B
  if (A.last>B.last) return 1;
  if (A.last<B.last) return -1;
  for (int i=A.last-1; i>=0; i--) {
    if      (A.N[i]>B.N[i]) return 1;
    else if (A.N[i]<B.N[i]) return -1;
  }
  return 0;
}

// bignum division by 2 (and assignment) - needed for bignum square root
void div2(bignum& A){ // A:=A/2 (for x element of [0...10^BASE10-1]
  A.N[A.last]=0;
  for (int i=0; i<A.last; i++){
    A.N[i]/=2;
    if (A.N[i+1]%2) A.N[i]+=5*POW10[BASE10-1];
  }
}

// return number of digits of bignum
int digits(bignum& A){
  int sol=(A.last-1)*BASE10;
  int i=0;
  while (A.N[A.last-1]/POW10[i] >= 10) ++i;
  return sol+i+1;
}

// bignum square root 
void sqrt(bignum& A, bignum& C){ // sqrt(A)=C
  // A has A.last digits
  // the square root of A must have between (digits(A)+1)/2 and (digits(A)+1)/2+1 
  // whereas digits(A) denotes num. digits in base 10
  bignum low,high,mid,sol,one,cmp;
  char One[]="1"; base(one,One);
	
  base(low,One);  shift10(low, (digits(A)+1)/2-1);
  base(high,One); shift10(high,(digits(A)+1)/2);
	
  while (comp(high,low)>=0){
    add(high,low,mid);
    div2(mid);
    mult(mid,mid,cmp);
    if (comp(cmp,A)<=0){
      assign(sol,mid);
      assign(low,mid);
      add(low,one,low);}
    else {
      assign(high,mid);
      sub(high,one,high);
    }
  }
  zerojustify(sol);
  assign(C,sol);
}

char S[BASE10*DIGITS];

int main(){
  precomp_pow10();
	
  bignum A,B,C;
  // test: base conversion and print bignum
  scanf("%s",S);
  base(A,S);
  scanf("%s",S);
  base(B,S);
  printf("base conversion for A: \n");
  for (int i=0; i<A.last; i++) printf("%lld ",A.N[i]);
  printf("\n");
  printf("print bignum: ");
  print(A);
  // test: bignum addition
  printf("bignum addition A+B:\n");
  add(A,B,C);
  print(A,false);  printf(" + "); print(B,false); printf(" = ");  print(C);   
  // test: bignum subtraction
  printf("bignum subtraction A-B:\n");
  sub(A,B,C);
  print(C);
  // test: bignum multiplication
  printf("bignum multiplication A*B:\n");
  mult(A,B,C);
  print(A,false); printf(" * "); print(B,true);
  printf(" = "); print(C);
  // test: square root
  printf("bignum square root:\n");
  printf("B = "); print(B);
  printf("sqrt(B)=\n");
  sqrt(B,C);
  print(C);
}
