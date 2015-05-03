/*
  Longest Common Subsequence Length (inefficient).

  Very inefficient, recursive LCS, O(2^n).

  (c) 2015 Josef Ziegler

*/

int lcs_length(char * A, char * B)
{
  if (*A == '\0' || *B == '\0') return 0;
  else if (*A == *B) return 1 + lcs_length(A+1, B+1);
  else return max(lcs_length(A+1,B), lcs_length(A,B+1));
}

int main(){
  char a[1000],b[1000];
  scanf("%s %s",a,b);
  printf("%d\n",lcs_length(a,b));
}
	 
