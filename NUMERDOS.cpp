#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 2010

int id = 0;
map<string, int> name_to_id;
map<int, string> id_to_name;

vector<int> adj[MAXN];
int d[MAXN];
bool vis[MAXN];

struct Autor {
  string nome_completo, sobrenome;
  int d;
  Autor(string _nome, int _d) {
    nome_completo = _nome;
    d = _d;
    sobrenome = _nome.substr(3);
  }  
};

bool cmp_autor(const Autor& a, const Autor& b) {
  if (a.sobrenome != b.sobrenome) return a.sobrenome < b.sobrenome;
  return a.nome_completo < b.nome_completo;  
}

vector<string> split(const string &s, char delim = ',') {
  stringstream ss(s);
  string item;  
  vector<string> tokens;
  while (std::getline(ss, item, delim)) {
    if (item.front() == ' ') item.erase(0, 1);
    if (item.back() == '.') item.erase(item.size() - 1, 1);
    tokens.push_back(item);
  }
  return tokens;
}

int get_id(const string& s) {
  if (name_to_id.find(s) == name_to_id.end()) {
    name_to_id[s] = id;
    id_to_name[id] = s;
    id++;
  }
  return name_to_id[s];
}

void bfs(int s) {  
  queue<int> q;
  for (int i = 0; i < id; i++) d[i] = INF, vis[i] = false;
  d[s] = 0;  
  q.push(s); vis[s] = true;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {      
      if (vis[v]) continue;
      d[v] = d[u] + 1;      
      q.push(v); vis[v] = true;
    }    
  }
  return;  
}

int main() {
  int n;
  int nt = 0;
  string p_erdos = "P. Erdos";
  while (scanf(" %d", &n) == 1 && n) {
    getchar();
    id = 0;
    name_to_id.clear();    
    id_to_name.clear();    
    for (int i = 0; i < MAXN; i++) adj[i].clear();
    
    for (int i = 0; i < n; i++) {      
      string line; getline(std::cin, line);      
      vector<string> names = split(line);         
      for (int i = 0; i < names.size(); i++) {
        int id_i = get_id(names[i]);        
        for (int j = 0; j < i; j++) {          
          int id_j = get_id(names[j]);          
          adj[id_i].push_back(id_j);
          adj[id_j].push_back(id_i);
        }        
      }   
    }      
    bfs(get_id(p_erdos));
    
    vector<Autor> autores;
    for (int i = 0; i < id; i++) autores.push_back(Autor(id_to_name[i], d[i]));
    sort(autores.begin(), autores.end(), cmp_autor);

    if (nt) printf("\n");
    printf("Teste %d\n", ++nt);
    for (int i = 0; i < autores.size(); i++) {
      if (autores[i].d == 0) continue;
      cout << autores[i].nome_completo << ": ";
      if (autores[i].d == INF) cout << "infinito" << endl;
      else cout << autores[i].d << endl;
    }    
  }
  return 0;
}
