#include <bits/stdc++.h>

using namespace std;

#define MAXN 2010010

int pd[MAXN];

int f91(int x) {
  int& ans = pd[x];
  if (ans != -1) return ans;
  
  if (x <= 100) ans = f91(f91(x + 11));
  else ans = x - 10;
  return ans;
}

int main() {
  int n;
  memset(pd, -1, sizeof(pd));
  while (scanf(" %d", &n) == 1 && n) {
    printf("f91(%d) = %d\n", n, f91(n));
  }
  return 0;
}
