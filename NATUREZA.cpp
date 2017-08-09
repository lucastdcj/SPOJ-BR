#include <bits/stdc++.h>

using namespace std;

#define MAXN 5010


map<string, int> dic;
vector<int> adj[MAXN];

bool vis[MAXN];

void dfs(int u) {
  vis[u] = true;
  for (int v : adj[u]) if (!vis[v]) dfs(v);
}

int main() {
  int n, m;
  while (scanf(" %d %d", &n, &m) == 2 && n + m) {
    dic.clear();
    for (int i = 0; i < n; i++) adj[i].clear();
    
    for (int i = 0; i < n; i++) {
      string nome; cin >> nome;
      dic[nome] = i;
    }
    for (int i = 0; i < m; i++) {
      string a, b; cin >> a >> b;
      adj[dic[b]].push_back(dic[a]);
      adj[dic[a]].push_back(dic[b]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) vis[j] = false;
      // Testa o tamanho da cadeia comecando por cada elemento.
      dfs(i);
      int cadeia = 0;
      for (int j = 0; j < n; j++) if (vis[j]) cadeia++;
      ans = max(ans, cadeia);
    }
    printf("%d\n\n", ans);  
  }  
  return 0;
}
