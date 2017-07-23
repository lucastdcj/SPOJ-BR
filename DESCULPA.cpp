#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 1010
 
int pd[MAXN];
 
int main() {
  int c, f;
  int nt = 0;
  while (scanf(" %d %d", &c, &f) == 2 && c + f > 0) {
    memset(pd, -1, sizeof(pd));
    int ans = 0;
    // Com tamanho 0, conseguimos 0 pedido de desculpas.
    pd[0] = 0;
    for (int i = 0; i < f; i++) {
      int n, d;
      scanf(" %d %d", &n, &d);
      // Percorremos de trás para frente, pois assim não repetimos uma mesma frase.
      for (int j = MAXN - 1; j >= 0; j--) {
        // Se não conseguimos nenhum pedido de desculpa com tamanho j, pulamos.
        if (pd[j] == -1) continue;
        if (j + n > c) continue;
        // Nesse caso, conseguimos um 
        pd[j + n] = max(pd[j + n], pd[j] + d);
        ans = max(pd[j + n], ans);
      }
    }
    if (nt) printf("\n");
    printf("Teste %d\n", nt + 1);
    printf("%d\n", ans);
    nt++;
  }
  return 0;
}
 
