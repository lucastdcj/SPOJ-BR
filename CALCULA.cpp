#include <bits/stdc++.h>

using namespace std;

#define MAIS 1
#define MENOS -1
#define MAXN 1010

char expressao[MAXN];

int main() {
  int n;
  int nt = 0;
  while (scanf(" %d", &n) == 1 && n) {
    scanf(" %s", expressao);
    n = strlen(expressao);
    int resultado = 0;
    int sinal = MAIS;
    for (int i = 0; i < n;) {
      int ni = i;
      int num = 0;
      while (ni < n && (expressao[ni] >= '0' && expressao[ni] <= '9')) {
        num *= 10;
        num += expressao[ni] - '0';
        ni++;
      }       
      resultado += sinal * num;      
      if (expressao[ni] == '+') sinal = MAIS;
      else sinal = MENOS;
      i = ni + 1;
    }
    printf("Teste %d\n%d\n\n", ++nt, resultado);
  }
  return 0;
}
