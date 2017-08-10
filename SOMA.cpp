#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; scanf(" %d", &n);
  int soma = 0;
  for (int i = 0; i < n; i++) {
    int x; scanf(" %d", &x);
    soma += x;
  }
  printf("%d\n", soma);
  return 0;
}
