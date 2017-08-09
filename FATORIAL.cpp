#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010010

typedef long long ll;

ll pd[MAXN];

ll solve(ll x) {
  // Verifica se já calculamos isso antes.
  ll& ans = pd[x];
  if (ans != -1) return ans;  
  
  // Caso base.
  if (x == 0) return 1LL;  
  
  ans = x * solve(x - 1);  
  while (ans % 10 == 0) ans /= 10;
  ans = ans % 1000000;
  
  return ans;  
}

int main() {
  int nt = 0;  
  memset(pd, -1, sizeof(pd));
  ll n;
  while (scanf(" %lld", &n) == 1) {
    printf("Instancia %d\n", ++nt);
    printf("%lld\n\n", solve(n) % 10);
  }
  return 0;
}
