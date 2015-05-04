/*
  Radixsort.

  (c) 2015 Josef Ziegler

*/

#include <stdio.h>
#define MAX 100
 
void radixsort(int *a, int n) {
  int b[MAX], m = a[0], exp = 1;
  for (int i = 0; i < n; i++)
    if (a[i] > m)
      m = a[i];

  while (m / exp > 0) {
    int bucket[10] = { 0 };

    for (int i = 0; i < n; i++)
      bucket[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];

    for (int i = n - 1; i >= 0; i--) 
      b[--bucket[(a[i] / exp) % 10]] = a[i];

    for (int i = 0; i < n; i++) 
      a[i] = b[i];
    exp *= 10;
  }
}
 
int main() {
  int a[8] = {170, 45, 75, 90, 802, 24, 2, 66};
  radixsort(a, 8);
  for (int i = 0; i < 8; i++)
    printf("%d ", a[i]);
}
