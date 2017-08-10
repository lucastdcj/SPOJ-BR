#include <bits/stdc++.h>

using namespace std;

int main() {
  int nt = 0;
  int n;
  while (scanf(" %d", &n) == 1 && n) {
    int soma_aldo = 0, soma_beto = 0;
    for (int i = 0; i < n; i++) {
      int x, y; scanf(" %d %d", &x, &y);
      soma_aldo += x; soma_beto += y;
    }
    printf("Teste %d\n", ++nt);
    if (soma_aldo > soma_beto) printf("Aldo\n\n");
    else printf("Beto\n\n");
  }  
  return 0;
}
