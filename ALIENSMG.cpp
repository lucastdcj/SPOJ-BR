#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; 
  while (scanf(" %d", &n) == 1 && n) {    
    vector<string> dnas;
    for (int i = 0; i < n; i++) {
      string dna; cin >> dna;
      // Ordena a string.
      sort(dna.begin(), dna.end());
      dnas.push_back(dna);
    }
    // Ordena o vetor de strings.
    sort(dnas.begin(), dnas.end());
    int ans = 0;
    for (int i = 0, ni = 0; i < n;) {
      ans++;
      // Pula todos DNAs iguais
      while (ni < n && dnas[ni] == dnas[i]) ni++;
      i = ni;
    }
    printf("%d\n", ans);
  }
  return 0;
}
