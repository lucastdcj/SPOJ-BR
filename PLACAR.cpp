#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> pis;

int main() {
  int nt = 0;
  int n;
  while (scanf(" %d", &n) == 1 && n) {
    vector<pis> alunos;
    for (int i = 0; i < n; i++) {
      pis aluno; cin >> aluno.second >> aluno.first;
      aluno.first *= -1;
      alunos.push_back(aluno);
    }
    sort(alunos.begin(), alunos.end());
    cout << "Instancia " << ++nt << endl;
    cout << alunos.back().second << endl << endl;
  }
  return 0;
}
