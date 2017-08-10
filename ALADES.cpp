#include <bits/stdc++.h>

using namespace std;

int main() {  
  int h1, m1, h2, m2;
  while (scanf(" %d %d %d %d", &h1, &m1, &h2, &m2) == 4 && h1 + m1 + h2 + m2) {
    if (m2 < m1) {
      m2 += 60;
      h2--;
    }    
    if (h2 < h1) {
      h2 += 24;
    }
    int minutos = 60 * (h2 - h1) + (m2 - m1);
    printf("%d\n", minutos);
  }
  return 0;
}
