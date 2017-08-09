#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int ngolpes;
int golpe[MAXN], nasce[MAXN], d[MAXN];
bool vis[MAXN];

int bfs(int s) {
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  vis[s] = true;
  d[s] = 0;
  q.push(s);

  while (!q.empty()) {    
    int cabecas = q.front(); q.pop();    
    for (int i = 0; i < ngolpes; i++) {
      if (cabecas < golpe[i]) continue;
      if (cabecas == golpe[i]) return d[cabecas] + 1;
      
      int novas_cabecas = cabecas - golpe[i] + nasce[i];
      if (novas_cabecas > 1000) continue;
      
      if (!vis[novas_cabecas]) {
        vis[novas_cabecas] = true;
        d[novas_cabecas] = d[cabecas] + 1;
        q.push(novas_cabecas);        
      }
    }
  }
  return -1;
}

int main() {
  while (scanf(" %d", &ngolpes) == 1 && ngolpes) {
    for (int i = 0; i < ngolpes; i++) scanf(" %d", &golpe[i]);
    for (int i = 0; i < ngolpes; i++) scanf(" %d", &nasce[i]);
    int ans = bfs(100);
    if (ans == -1) printf("cavaleiro morreu\n");
    else printf("%d\n", ans);    
  }
  return 0;
}
