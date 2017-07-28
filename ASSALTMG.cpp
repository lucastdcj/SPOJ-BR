#include <bits/stdc++.h>

using namespace std;

#define MAXN 110

int chaves_mask[MAXN];

int main() {
  int nt; scanf(" %d", &nt);
  while (nt--) {
    int m, d; scanf(" %d %d", &m, &d);
    for (int i = 0; i < d; i++) {
      int n; scanf(" %d", &n);
      int mask = 0;
      for (int j = 0; j < n; j++) {
        int x; scanf(" %d", &x);
        mask |= (1 << x);
      }
      chaves_mask[i] = mask;
    }
    
    int ans = -1;
    for (int i = 0; i < 1 << (d); i++) {
      int mask = 0;
      int num_diretores = 0;
      for (int j = 0; j < d; j++) {        
        if ((1 << j) & i) {
          mask |= chaves_mask[j];
          num_diretores++;
        }                
      }
      int num_chaves = 0;
      for (int j = 0; j < 32; j++) {
        if (mask & (1 << j)) {
          num_chaves++;
        }
      }
      if (num_chaves >= m) {
        if (ans == -1 || num_diretores < ans) ans = num_diretores;
      }
    }
    if (ans == -1) printf("Desastre!\n");
    else printf("%d\n", ans);  
  }
  return 0;
}
