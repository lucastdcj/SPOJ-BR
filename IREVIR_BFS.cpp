#include <bits/stdc++.h>

using namespace std;

#define MAXN 2010

vector<int> adj[MAXN];
bool vis[MAXN];

void bfs(int s) {
  queue<int> q;
  vis[s] = true;
  q.push(s);
  while (!q.empty()) {    
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
      if (!vis[v]) {
        vis[v] = true;
        q.push(v);
      }
    }
  }
}

int main() {
  int n;
  while(scanf(" %d", &n) == 1 && n) {
    int m; scanf(" %d", &m);
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < m; i++) {
      int a, b, c;
      scanf(" %d %d %d", &a, &b, &c); a--; b--;
      adj[a].push_back(b);
      if (c == 2) adj[b].push_back(a);      
    }
    int ok = 1;
    for (int i = 0; i < n && ok; i++) {
      for (int j = 0; j < n; j++) vis[j] = false;
      bfs(i);
      for (int j = 0; j < n; j++) if (!vis[j]) ok = 0;    
    }
    printf("%d\n", ok);  
  }
  return 0;
}
