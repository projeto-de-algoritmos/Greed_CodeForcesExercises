#include <utility>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const int MAXIMO = 105000;
const long long INFINITO = (long long)1e12;
struct edge {
  int destino, peso;
};
vector<edge> g[MAXIMO];
long long dist[MAXIMO];
int par[MAXIMO];
int vertices, edges;
priority_queue<pair<long long, int>> fila;
vector<int> resposta;
edge e;

int main() {
  scanf("%d %d", &vertices, &edges);
  for (int i = 1; i <= edges; i++) {
    int inicio, fim, peso;
    scanf("%d %d %d", &inicio, &fim, &peso);
    e.destino = fim;
    e.peso = peso;
    g[inicio].push_back(e);
    e.destino = inicio;
    g[fim].push_back(e);
  }
  fila.push(make_pair(0, 1));
  for (int i = 2; i <= vertices; i++) {
    dist[i] = INFINITO;
    fila.push(make_pair(-INFINITO, i));
  }
  while (!fila.empty()) {
    int atual = fila.top().second;
    long long dist_atual = -fila.top().first;
    fila.pop();
    if (dist_atual > dist[atual])
      continue;
    for (int i = 0; i < (int)g[atual].size(); i++) {
      int to = g[atual][i].destino, peso = g[atual][i].peso;
      if (dist_atual + peso < dist[to]) {
        dist[to] = dist_atual + peso;
        par[to] = atual;
        fila.push(make_pair(-dist[to], to));
      }
    }
  }
  if (dist[vertices] == INFINITO) {
    printf("-1");
    return 0;
  }
  int atual = vertices;
  while (par[atual] != 0) {
    resposta.push_back(atual);
    atual = par[atual];
  }
  resposta.push_back(1);
  reverse(resposta.begin(), resposta.end());
  for (int i = 0; i < (int)resposta.size(); i++)
    printf("%d ", resposta[i]);

  return 0;
}