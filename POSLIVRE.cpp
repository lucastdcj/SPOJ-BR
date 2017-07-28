#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

bool esta_ocupado[MAXN][MAXN];

int main() {
  int w, h, n;
  while (scanf(" %d %d %d", &w, &h, &n) == 3 && w + h + n) {
    for (int i = 1; i <= w; i++) {
      for (int j = 1; j <= h; j++) {
        // Inicialmente marcamos todas posicoes livres.
        esta_ocupado[i][j] = false;
      }
    }
    for (int i = 0; i < n; i++) {
      int x1, y1, x2, y2;
      scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);    
      if (x1 > x2) swap(x1, x2);
      if (y1 > y2) swap(y1, y2);
      for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
          esta_ocupado[i][j] = true;
        }
      }
    }
         
    int livres = 0;
    for (int i = 1; i <= w; i++) {
      for (int j = 1; j <= h; j++) {
        if (!esta_ocupado[i][j]) livres++;
      }
    }
    if (livres == 0) {
      printf("There is no empty spots.\n");
    } else if (livres == 1) {
      printf("There is one empty spot.\n");
    } else {
      printf("There are %d empty spots.\n", livres);
    }
  
  }
  return 0;
}
