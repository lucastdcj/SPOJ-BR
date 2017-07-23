#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 200010
int v[MAXN];

int main() {
  int n, m;
  while (scanf(" %d %d", &n, &m) == 2 && n + m) {
    for (int i = 0; i < m; i++) scanf(" %d", &v[i]);
    int ans = n;
    for (int i = 0, pos = i; i < m; i++) {
      while (pos < m && v[pos] - v[i] + 1 <= n) pos++;
      ans = min(ans, n - ((pos - 1) - i + 1));
    }
    for (int i = m - 1, pos = i; i >= 0; i--) {
      while (pos >= 0 && v[i] - v[pos] + 1 <= n) pos--;
      ans = min(ans, n - (i - (pos + 1) + 1));
    }
    printf("%d\n", ans);
  }
  return 0;
}
