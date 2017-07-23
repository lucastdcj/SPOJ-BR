#include <cstdio>

using namespace std;

int main() {
  int nt = 0;
  int n; 
  while (scanf(" %d", &n) == 1 && n) {
    int ganhador = 0;
    for (int i = 1; i <= n; i++) {
      int x; scanf(" %d", &x);
      if (x == i) ganhador = i;
    }
    if (nt) printf("\n");
    printf("Teste %d\n", ++nt);
    printf("%d\n", ganhador);
  }
  return 0;
}
