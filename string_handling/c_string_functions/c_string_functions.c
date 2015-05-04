/*
  Some C string functions applied.

  (c) 2015 Josef Ziegler

*/

#include "stdio.h"
#include "ctype.h"
#include "string.h"

char c;
char A[256];
char B[256];
char T[512];
int main(){
  printf("type a character\n");
  c=getchar();

  if (isalpha(c)) printf("c is either upper or lower case\n");
  else printf("c is NOT upper or lower case\n");
  
  if (isupper(c)) printf("c is upper case\n");
  else{ printf("c is NOT upper case: %c!=%c\n",c,toupper(c)); tolower(c);}
  
  if (islower(c)) printf("c is lower case\n");
  else{ printf("c is NOT lower case: %c!=%c\n",c,tolower(c)); toupper(c);}
  
  if (isdigit(c)) printf("c is a numerical digit\n");
  else printf("c is NOT a numerical digit\n");

  if (ispunct(c)) printf("c is a punctuation symbol\n");
  else printf("c is NOT a punctuation symbol\n");

  if (isxdigit(c)) printf("c is a hexadecimal digit\n");
  else printf("c is NOT a hexadecimal digit\n");
  
  if (isprint(c)) printf("c is a printable character\n");
  else printf("c is NOT a printable character\n");

  printf("\n\ntype a string\n");
  scanf("%s",A);
  printf("now type a substring\n");
  scanf("%s",B);
  
  printf("strncat A B\n");
  strcpy(T,A);
  printf("%s\n",strncat(T,B,strlen(B)));
  
  printf("strcmp A B\n");
  printf("%d\n",strcmp(A,B));
  
  printf("memset T to 0\n");
  memset(T,0,512);
  printf("%s\n",T);

  char *ptr;
  printf("find B in A\n");
  ptr=strstr(A,B);
  if (ptr!=NULL){
    printf("found at:");
    while ((*ptr)!=0){
      printf("%c",*ptr);
      ptr++;}
    putchar(10);}
  else
    printf("NOT FOUND\n");
}
  
  
    

