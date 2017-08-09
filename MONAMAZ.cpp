#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010
#define INF 0x3f3f3f3f

struct pt {
  int id, x, y, d;
};

pt estacoes[MAXN], aux[MAXN];

bool cmp(const pt& a, const pt& b) {
  if (a.d != b.d) return a.d < b.d;
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}

vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int u) {
  vis[u] = true;
  for (int v : adj[u]) if (!vis[v]) dfs(v);
}

int main() {
  int n;
  while (scanf(" %d", &n) == 1 && n) {
    for (int i = 0; i < n; i++) {
      scanf(" %d %d", &estacoes[i].x, &estacoes[i].y);
      estacoes[i].id = i;      
      adj[i].clear();
    }
    for (int i = 0; i < n; i++) {
      pt a, b;
      a.d = INF; b.d = INF;
      for (int j = 0; j < n; j++) {
        if (j == i) continue;
        pt p = estacoes[j];
        p.x = estacoes[j].x - estacoes[i].x;
        p.y = estacoes[j].y - estacoes[i].y;        
        p.d = p.x * p.x + p.y * p.y;
        if (cmp(p, a)) {
          b = a;
          a = p;
        }
        else if (cmp(p, b)) b = p;
      }
      
      if (n > 1) adj[i].push_back(a.id); 
      if (n > 2) adj[i].push_back(b.id);     
    }
    
    int ans = 0;
    for (int i = 0; i < n && ans < n; i++) {
      for (int j = 0; j < n; j++) vis[j] = false;
      // Testa o tamanho da cadeia comecando por cada elemento.
      dfs(i);
      int cadeia = 0;
      for (int j = 0; j < n; j++) if (vis[j]) cadeia++;
      ans = max(ans, cadeia);
    }
    if (ans == n) printf("All stations are reachable.\n");
    else printf("There are stations that are unreachable.\n");
  }
  return 0;
}
