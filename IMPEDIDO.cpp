#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 20

int atacantes[MAXN], defensores[MAXN];

int main() {
  int na, nd;
  while (scanf(" %d %d", &na, &nd) == 2 && na + nd) {
    // Le os dois vetores.
    for (int i = 0; i < na; i++) scanf(" %d", &atacantes[i]);
    for (int i = 0; i < nd; i++) scanf(" %d", &defensores[i]);
    // Ordena o vetor de atacantes e defensores.
    sort(atacantes, atacantes + na);
    sort(defensores, defensores + nd);
    if (atacantes[0] < defensores[1]) printf("Y\n");
    else printf("N\n");
  }
  return 0;
}
