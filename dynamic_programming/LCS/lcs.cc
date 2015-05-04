/*
  Longest Common Subsequence (LCS).

  (c) 2015 Josef Ziegler

*/

#include <cstdio>
#include <cstdlib>
#include <string>
#define MATCH 0
#define INSERT 1
#define DELETE 2
#define MAXLEN 100
using namespace std;

int opt[3]; /* cost of the three options */
typedef struct {
  int cost;    /* cost of reaching this cell */
  int parent;  /* parent cell */
} cell; 
cell m[MAXLEN+1][MAXLEN+1]; /* dynamic programming table */

void row_init(int i){
  m[0][i].cost = i;
  if (i>0)
    m[0][i].parent=INSERT;
  else
    m[0][i].parent=-1;
}

void column_init(int i){
  m[i][0].cost = i;
  if (i>0)
    m[i][0].parent=DELETE;
  else
    m[i][0].parent=-1;}

int match(char c, char d){
  if (c==d) return 0;
  else return 1000000;}

int indel(char c){
  return 1;}
  
void goal_cell(char * s, char * t, int * i, int * j){
  *i = strlen(s)-1;
  *j = strlen(t)-1;}

int string_comp(char * s, char * t){
  for (int p=0; p<MAXLEN; p++){ // initialize
    row_init(p);
    column_init(p);}
  int i,j;
  for (i=1; i < strlen(s); i++){
    for (j=1; j < strlen(t); j++){
      opt[MATCH] = m[i-1][j-1].cost + match(s[i],t[j]);
      opt[INSERT] = m[i][j-1].cost + indel(t[j]);
      opt[DELETE] = m[i-1][j].cost + indel(s[i]);
      
      m[i][j].cost = opt[MATCH];
      m[i][j].parent = MATCH;
      for (int k=INSERT; k<=DELETE; k++)
	if (opt[k] < m[i][j].cost){
	  m[i][j].cost = opt[k];
	  m[i][j].parent = k;}
    }
  }
  goal_cell(s,t,&i,&j);
  return(m[i][j].cost);
}
    

int main(){
  while (1){
    char str1[MAXLEN];
    char str2[MAXLEN];
    str1[0]=' '; str2[0]=' ';
    scanf("%s %s",&(str1[1]),&(str2[1]));
    printf("|%s|%s|\n%d %d\n",str1,str2,strlen(str1),strlen(str2));
    printf("PARENT \n",string_comp(str1,str2));
    for (int i=0; i<max(strlen(str1),strlen(str2)); i++){
      for (int j=0; j<max(strlen(str1),strlen(str2)); j++){
	printf("%d ",m[j][i].parent);}
      printf("\n");}
  }
}
  
