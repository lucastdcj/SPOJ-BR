#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct pt {
  ll x, y, z;
  explicit pt(ll _x, ll _y, ll _z) : x(_x), y(_y), z(_z) {}
  
  pt operator - (pt q) { 
    return pt(x - q.x, y - q.y, z - q.z); 
  }
  
  bool operator == (pt q) {
    return x == q.x && y == q.y && z == q.z;
  }
  
  ll operator % (pt q) {
    return x * q.y + y * q.z + z * q.x - x * q.z - z * q.y - y * q.x;
  }
};

// Calcula o determinante de:
// |a.x a.y a.z|
// |b.x b.y b.z|
// |c.x c.y c.z| 
ll ProdutoMisto(pt a, pt b, pt c) {
  return a.x * b.y * c.z + a.y * b.z * c.x + a.z * b.x * c.y
       - a.y * b.x * c.z - a.x * b.z * c.y - a.z * b.y * c.x;
}

int main () {
  int nt; scanf(" %d", &nt);
  int t = 0;
  while (nt--) {
    int n; scanf(" %d", &n);
    
    vector<pt> pontos;
    vector<int> cnt;
        
    for (int i = 0; i < n; i++) {
      ll x, y, z;
      scanf(" %lld %lld %lld", &x, &y, &z);
      pt p = pt(x, y, z);
      bool has_equal = false;
      for (int j = 0; j < pontos.size(); j++) {
        if (p == pontos[j]) {
          has_equal = true;
          cnt[j]++;          
        }
      }
      if (!has_equal) {
        pontos.push_back(p);
        cnt.push_back(1);
      }
    }
    int ans = 0;    
    int sz = pontos.size();
    for (int i = 0; i < sz; i++) {
      ans = max(ans, cnt[i]); 
      for (int j = i + 1; j < sz; j++) {        
        ans = max(ans, cnt[i] + cnt[j]); 
        pt i_j = pontos[j] - pontos[i];
        for (int k = j + 1; k < sz; k++) {          
          ans = max(ans, cnt[i] + cnt[j] + cnt[k]); 
          pt i_k = pontos[k] - pontos[i];
          if (i_k % i_j == 0) {
            int nessa_linha = 0;                        
            for (int l = 0; l < sz; l++) {
              pt i_l = pontos[l] - pontos[i];
              if (i_l % i_k == 0 && i_l % i_j == 0) {
                nessa_linha += cnt[l];
              }
            }
            ans = max(ans, nessa_linha);
          } else {
            // 3 pontos distintos determinam um plano, vamos ver quantos 
            // pontos estão no plano determinado por i, j, k.
            int nesse_plano = 0;
            for (int l = 0; l < sz; l++) {
              pt i_l = pontos[l] - pontos[i];
              if (ProdutoMisto(i_j, i_k, i_l) == 0) {
                nesse_plano += cnt[l];
              }
            }
            ans = max(ans, nesse_plano);
          }
        }      
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
