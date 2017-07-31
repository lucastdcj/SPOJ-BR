#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; 
  while (scanf(" %d", &n) == 1 && n) {
    int ans = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
      int x; scanf(" %d", &x);
      if (s < 0) s = 0;
      s += x;
      ans = max(ans, s);
    }
    if (ans == 0) printf("Losing streak.\n");
    else printf("The maximum winning streak is %d.\n", ans);    
  }
  return 0;
}
