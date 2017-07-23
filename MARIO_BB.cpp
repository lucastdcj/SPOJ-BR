#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 200010
int v[MAXN];

int main() {
  int n, m;
  while (scanf(" %d %d", &n, &m) == 2 && n + m) {
    for (int i = 0; i < m; i++) scanf(" %d", &v[i]);
    int ans = n;
    for (int i = 0; i < m; i++) {
      int ini, fim, pos;

      // Busca binária testando começando em i.
      ini = i, fim = m - 1;
      pos = i;      
      while (ini <= fim) {
        int meio = (ini + fim) / 2;
        // Queremos a posição mais a direita tal que seja menor ou igual a n.
        if (v[meio] - v[i] + 1 <= n) {
          pos = meio;
          ini = meio + 1;
        } else {
          fim = meio - 1;
        }
      }
      ans = min(ans, n - (pos - i + 1));
      
      // Queremos a posição mais a esquerda tal que ainda seja menor ou igual a n.
      ini = 0, fim = i;
      pos = i;
      while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (v[i] - v[meio] + 1 <= n) {
          pos = meio;
          fim = meio - 1;
        } else {
          ini = meio + 1;
        }
      }
      ans = min(ans, n - (i - pos + 1));
    }
    printf("%d\n", ans);
  }
  return 0;
}
