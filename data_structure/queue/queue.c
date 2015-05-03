/* 
   Queue.

   (c) 2015 Josef Ziegler

*/

#include "stdio.h"
#define QUEUESIZE 100

typedef struct{
  int q[QUEUESIZE+1]; /* body of queue */
  int first; /* position of first element */
  int last; /* position of last element */
  int count; /* number of queue elements */
} queue;

queue q;

void init_queue(){
  q.first=0;
  q.last=QUEUESIZE-1;
  q.count=0;}

void enqueue(int x){
  if (q.count>=QUEUESIZE){
    printf("Warning: queue overflow enqueue x=%d\n",x);}
  else {
    q.last=(q.last+1)%QUEUESIZE;
    q.q[q.last]=x;
    q.count++;}
}

int dequeue(){
  int x;
  if (q.count <= 0){
    printf("Warning: empty queue dequeue\n");}
  else {
    x=q.q[q.first];
    q.first=(q.first+1)%QUEUESIZE;
    q.count--;}
  return(x);
}

int empty(){
  if (q.count <= 0) return(1);
  else return(0);
}   

int main(){
  printf("stop by inserting -1 at the end\n");
  printf("insert:\n");
  init_queue();
  int m;
  do{
    scanf("%d",&m);
    enqueue(m);
  }while(m!=-1);
  printf("number of elements (including -1): %d\n",q.count);
  printf("first and last element: %d, %d\n",q.q[q.first], q.q[q.last]);
  printf("remove and print number of elements:");
  int x,i;
  scanf("%d",&x);
  for (i=0;i<x;i++)
    printf("%d\n",dequeue());
}
