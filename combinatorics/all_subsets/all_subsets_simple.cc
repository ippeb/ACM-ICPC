// Generates all subsets of a given length.
#include <iostream>
#include <cstring>
using namespace std;

void all_subsets(string& S, int l) {
  if (l == -1) {
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
  tmp.resize(l);
  all_subsets(tmp, l);
}
