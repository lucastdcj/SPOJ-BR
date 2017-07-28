#include <cstdio>
 
using namespace std;
 
int fatorial(int x) {
  if (x <= 1) return 1;
  return x * fatorial(x - 1);
}
 
int main() {
  int x; scanf(" %d", &x);
  printf("%d\n", fatorial(x));
  return 0;
} 
