/* 
   Dictionary (STL Map).

   (c) 2015 Josef Ziegler
   
*/

#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

struct strCmp{
  bool operator()(char* s1, char* s2){
    return(strcmp(s1,s2)<0);}
};

map <char*,int,strCmp> M;
map <char*, int>::iterator iter;
char S[10000];
char SS[10000][10000];
int  v;

int main(){
  M.clear(); /* not really necessary though */
  printf("insert your strings with the according values -> string - value - newline\n");
  printf("stop by inserting 'STOP' and any value\n");
  int i=0;
  do{  
    scanf("%s",SS[i]);
    scanf("%d",&v);    
    M.insert(make_pair(SS[i],v));
    i++;
  } while (strcmp(SS[i-1],"STOP")!=0);
  printf("'y' empty(), 'p' print all pairs, 's' size(), 'f' find(), 'c' clear and 'e' erase()\n");
  printf(" type q to quit\n");
  char c;
  while (1){
    c=getchar();
    if (c=='y'){
      if (M.empty())
	printf("empty\n");
      else
	printf("not empty\n");}
    else if (c=='p'){
      for (iter=M.begin(); iter!=M.end(); iter++)
	printf("%s %d\n",iter->first,iter->second);}
    else if (c=='s'){
      printf("%d\n",M.size());}
    else if (c=='f'){
      printf("what do you want to look for?\n");
      scanf("%s",S);
      iter=M.find(S);
      if (iter==M.end())
	printf("Not found\n");
      else printf("found:\n%s %d\n",(*iter).first,iter->second);
    }
    else if(c=='c'){
      M.clear();}
    else if(c=='e'){
      printf("what do you want to erase?\n");
      scanf("%s",S);
      iter=M.find(S);
      if (iter==M.end())
	printf("Not found\n");
      else{      M.erase(iter);
	printf("erased\n");}
    }
    else if(c=='q'){
      break;}
  }
}
    
       
      
      
