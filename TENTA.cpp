#include <bits/stdc++.h>

using namespace std;

int n;
int v[10];

int main() {
  while (scanf(" %d", &n) == 1 && n) {
    for (int i = 0; i < n; i++) scanf(" %d", &v[i]);
    sort(v, v + n);
    do {
      for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", v[i]);
      }
      printf("\n");
    } while (next_permutation(v, v + n)); // http://www.cplusplus.com/reference/algorithm/next_permutation/
    printf("\n");
  }
  return 0;
}
