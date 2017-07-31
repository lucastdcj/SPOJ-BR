#include <bits/stdc++.h>

using namespace std;

#define MAXN 2000010

int pd[MAXN];

int solve(int n, int m) {
  if (n <= m) return 1;  
  return solve(n / 2, m) + solve((n + 1) / 2, m);
}

// Note que a unica diferenca entre a solucao com programacao dinamica e
// sem é que memorizamos a resposta, assim evitamos de chamar recursivamente
// a funcao diversas vezes.
int solve_pd(int n, int m) {
  if (n <= m) return 1;  
  if (pd[n] != -1) return pd[n];
  pd[n] = solve_pd(n / 2, m) + solve_pd((n + 1) / 2, m);
  return pd[n];  
}

int main() {
  int n, m;
  while (scanf(" %d %d", &n, &m) == 2 && n + m) {
    memset(pd, -1, sizeof(pd));
    printf("%d\n", solve_pd(n, m));  
  }
  return 0;
}
