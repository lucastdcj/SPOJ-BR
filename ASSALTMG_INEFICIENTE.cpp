#include <bits/stdc++.h>

using namespace std;

#define MAXN 110

// As chaves do diretor i.
vector<int> chaves[MAXN];

int ans;
int m, d; 

void solve(int pos, int num_diretores, const set<int>& s) {
  if (pos == d) {
    if (s.size() >= m) {
      if (ans == -1 || num_diretores < ans) ans = num_diretores;
    }
    return;
  }
  // Caso o diretor pos não seja considerado.
  solve(pos + 1, num_diretores, s);
  
  set<int> new_s = s;
  // Caso o diretor pos seja considerado, temos que adicionar as chaves
  // dele no set.
  for (int chave : chaves[pos]) {
    new_s.insert(chave);
  }
  solve(pos + 1, num_diretores + 1, new_s);
}

int main() {
  int nt; scanf(" %d", &nt);
  while (nt--) {
    scanf(" %d %d", &m, &d);
    for (int i = 0; i < d; i++) {
      chaves[i].clear();
      int n; scanf(" %d", &n);      
      for (int j = 0; j < n; j++) {
        int x; scanf(" %d", &x);
        chaves[i].push_back(x);
      }      
    }
    ans = -1;
    set<int> s;
    solve(0, 0, s);    
    if (ans == -1) printf("Desastre!\n");
    else printf("%d\n", ans);  
  }
  return 0;
}
