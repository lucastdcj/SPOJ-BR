#include <iostream>
#include <cmath>
using namespace std;

int main () {
  int l, c, r1, r2; 
  while (scanf(" %d %d %d %d", &l, &c, &r1, &r2) == 4 && l + c + r1 + r2) {
    if (2 * max(r1, r2) > min(l, c)) {
      printf("N\n");
    } else {
      int R = r1 + r2;
      if ((l - R) * (l - R) + (c - R) * (c - R) >= R * R) {
        printf("S\n");
      } else {
        printf("N\n");
      }
    }
  }
  return 0;
}
