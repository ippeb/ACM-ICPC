/*
  2-dimensional Binary Indexed Tree (Fenwick Tree).

  Applies a two-dimensional binary indexed tree in its purest form.
  This code solves the SPOJ problem MATSUM 
  (http://www.spoj.com/problems/MATSUM/).

  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <iostream>
#include "string.h"
#define MAX 1025
using namespace std;

int tree[MAX][MAX],t,n,a,b,c,d;
int F[MAX][MAX];

void update(int x, int y, int val){
  x++;
  y++;
  while (x <= MAX){
    int y1=y;
    while (y1 <= MAX){
      tree[x][y1]+=val;
      y1+=y1&-y1;}
    x+=x&-x;}
}
  
int read(int x, int y){
  x++;
  y++;
  int sum=0;
  while (x>=1){
    int y1=y;
    while (y1>=1){
      sum+=tree[x][y1];
      y1-=y1&-y1;}
    x-=x&-x;}
  return sum;
}

char S[4];

int main(){
  scanf("%d",&t);
  while (t--){
    memset(tree,0,sizeof tree);
    memset(F,0,sizeof F);
    scanf("%d",&n);
    while (1){
      scanf("%s",&S);
      if (S[0]=='E') break;
      if (S[2]=='T'){
	scanf("%d %d %d",&a,&b,&c);
	update(a,b,c-F[a][b]);
	F[a][b]=c;
      }
      else{
	scanf("%d %d %d %d",&a,&b,&c,&d);
	printf("%d\n",read(c,d)+read(a-1,b-1)-read(a-1,d)-read(c,b-1));
      }
    }
    printf("\n");
  }
  return 0;
}




