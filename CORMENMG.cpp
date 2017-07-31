#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define MAXN 2000010
int v[MAXN];

// Solucao mais simples, mas fica 42 * n o que é ok para esse problema,
// mas caso aumentasse 42, poderia ficar quadrática.
vector<pii> build_seg(int n) {
  vector<pii> segs;    
  for (int i = 0; i < n; i++) {
    int soma = 0;
    int j = i;
    for (; j < n && soma < 42; j++) soma += v[j];
    if (soma == 42) segs.push_back(pii(j - 1, i));
  }
  return segs;
}

// Solucao usando dois ponteiros, a mais eficiente de todas.
vector<pii> build_seg_2p(int n) {
  vector<pii> segs;
  int soma = 0;
  // ni vai guardar a ultima posicao tal que v[i] + v[i + 1] + ... + v[ni] < 42
  for (int i = 0, ni = 0; i < n; i++) {
    while (ni < n && soma + v[ni] < 42) {
      soma += v[ni];
      ni++;
    }
    if (ni < n && soma + v[ni] == 42) segs.push_back(pii(ni, i));
    soma -= v[i];
  }
  return segs;
}

// Solucao usando bisca binaria, O(nlgn)
vector<pii> build_seg_bb(int n) {
  vector<pii> segs;
  vector<int> s_acc;
  int soma = 0;
  for (int i = 0; i < n; i++) {
    soma += v[i];
    s_acc.push_back(soma);
  }
  for (int i = 0; i < n; i++) {
    int s = (i) ? s_acc[i - 1] : 0;
    int ini = 0, fim = n - 1;
    int ans = -1;
    while (ini <= fim) {
      int meio = (ini + fim) / 2;
      if (s_acc[meio] - s <= 42) {
        ans = meio;
        ini = meio + 1;
      } else {
        fim = meio - 1;
      }     
    }
    if (ans != -1 && s_acc[ans] - s == 42) {
      segs.push_back(pii(ans, i));
    }
  }
  return segs;
}

int main() {
  int nt; scanf(" %d", &nt);
  while (nt--) {
    int n; scanf(" %d", &n);
    for (int i = 0; i < n; i++) scanf(" %d", &v[i]);
    vector<pii> segs = build_seg(n);    
    // vector<pii> segs = build_seg_2p(n);    
    // vector<pii> segs = build_seg_bb(n);    
    sort(segs.begin(), segs.end());
    int ans = 0;
    int last = -1;
    for (int i = 0; i < segs.size(); i++) {
      int ini = segs[i].second;
      int fim = segs[i].first;
      if (ini > last) {
        ans++;
        last = fim;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}  
