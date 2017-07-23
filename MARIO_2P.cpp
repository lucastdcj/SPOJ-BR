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
    for (int i = 0, ni = i; i < m; i++) {
      while (ni < m && v[ni] - v[i] + 1 <= n) ni++;
      ans = min(ans, n - ((ni - 1) - i + 1));
    }
    for (int i = m - 1, ni = i; i >= 0; i--) {
      while (ni >= 0 && v[i] - v[ni] + 1 <= n) ni--;
      ans = min(ans, n - (i - (ni + 1) + 1));
    }
    printf("%d\n", ans);
  }
  return 0;
}
