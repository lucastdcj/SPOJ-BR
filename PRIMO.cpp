#include <bits/stdc++.h>

using namespace std;

int main() {  
  int n; scanf(" %d", &n);
  n = abs(n);
  bool primo = true;
  for (int i = 2; i * i <= n && primo; i++) {
    if (n % i == 0) primo = false;
  }
  if (primo) printf("sim\n");
  else printf("nao\n");
  return 0;
}
