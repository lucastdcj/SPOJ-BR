#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int soma_linha[MAXN], soma_coluna[MAXN];

int main() {  
  int n, m; scanf(" %d %d", &n, &m);
  int produtividade = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x; scanf(" %d", &x);
      
      soma_linha[i] += x;
      soma_coluna[j] += x;      
    }
  }
  for (int i = 0; i < n; i++) produtividade = max(produtividade, soma_linha[i]);
  for (int i = 0; i < m; i++) produtividade = max(produtividade, soma_coluna[i]);
  printf("%d\n", produtividade);
  return 0;
}
