/*
  All subsets (int) (version 2).

  Constructing all subsets of 1, 2, ..., n via backtracking.

  (c) 2015 Josef Ziegler

*/

#include <iostream>
#include <cstring>
using namespace std;

void all_subsets(string& S, int l) {
  if (l == 0) {
    cout << S << endl;
    return;
  }

  for (int i = 0; i < 2; i++) {
    S[l] = i + '0';
    all_subsets(S, l-1);
  }
}

int main() {
  int l;
  cin >> l;
  string tmp("");
  tmp.resize(l+1);
  all_subsets(tmp, l);
}
