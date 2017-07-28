#include <bits/stdc++.h>

using namespace std;

#define MAXN 110

// As chaves do diretor i.
int chaves_mask[MAXN];

int ans;
int m, d; 

void solve(int pos, int num_diretores, int mask) {
  if (pos == d) {
    int num_chaves = 0;
    for (int j = 0; j < 32; j++) if (mask & (1 << j)) num_chaves++;
    if (num_chaves >= m) {
      if (ans == -1 || num_diretores < ans) ans = num_diretores;
    }
    return;
  }
  // Caso o diretor pos não seja considerado.
  solve(pos + 1, num_diretores, mask);
   
  // Caso o diretor pos seja considerado, temos que adicionar as chaves
  // dele na máscara.
  solve(pos + 1, num_diretores + 1, mask | chaves_mask[pos]);
}

int main() {
  int nt; scanf(" %d", &nt);
  while (nt--) {
    scanf(" %d %d", &m, &d);
    for (int i = 0; i < d; i++) {
      int n; scanf(" %d", &n);
      int mask = 0;
      for (int j = 0; j < n; j++) {
        int x; scanf(" %d", &x);
        mask |= (1 << x);
      }
      chaves_mask[i] = mask;
    }
    ans = -1;    
    solve(0, 0, 0);    
    if (ans == -1) printf("Desastre!\n");
    else printf("%d\n", ans);  
  }
  return 0;
}
