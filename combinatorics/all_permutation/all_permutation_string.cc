/* 
   All permutation (string).

   Constructs all permutations of a given input string via backtracking.
   Note that repetitions occur if there are letters in the input string 
   that appear more than once.

   (c) 2015 Josef Ziegler

*/

#include <iostream>
#include <cstring>
using namespace std;

void permute(string& S, int at) {
  if (at == S.length()) 
    cout << S << endl;

  for (int i = at; i < S.length(); i++) {
    char tmp = S[at];
    S[at]=S[i];
    S[i]=tmp;
    permute(S, at + 1);
    S[i]=S[at]; // two lines only needed if we pass
    S[at]=tmp;  // S as a reference
  }
}


int main() {
  string tmp;
  cin >> tmp;
  permute(tmp, 0);
}
