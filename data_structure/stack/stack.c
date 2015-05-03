/* 
  Stack.

  (c) 2015 Josef Ziegler

*/

#include "stdio.h"
#define STACKSIZE 100000

typedef struct{
  int s[STACKSIZE+1]; /* body of stack */
  int last; /* position of last element */
  int count; /* number of stack elements */
} stack;

stack s;

void init_stack(){
  s.last=-1;
  s.count=0;
}

void push(int x){
  if (s.count >= STACKSIZE)
    printf("WARNING: stack overflow push x=%d\n",x);
  else{
    s.s[++s.last]=x;
    s.count++;}
}

int pop(){
  int x;
  if (s.count <= 0)
    printf("Warning: empty stack pop\n");
  else{
    x=s.s[s.last];
    s.last--;
    s.count--;}
  return(x);
}
    
int empty(){
  if (s.count<=0) return(1);
  else return(0);
}
		  
    
int main(){
  init_stack();
  printf("insert numbers, stop with -1\n");
  int m;
  do{
    scanf("%d",&m);
    push(m);
  }while (m!=-1);
  printf("number of items: %d\n",s.count);
  printf("insert number of items to pop and print: ");
  scanf("%d",&m);
  int i;
  for (i=0; i<m; i++)
    printf("%d\n",pop());
}
  
  
