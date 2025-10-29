// https://www.acmicpc.net/problem/1219
#include <bits/stdc++.h>
using namespace std;

int N, SC, DC, M;
int s, d, c, v;
vector<pair<pair<int, int>, int>> edges;
int INF = 987'654'321;
int dist[50];
int earnings[50];

void printE () {
  for (int i = 0; i < M; ++i) {
    cout << edges[i].first.first << " " << edges[i].first.second << " " << edges[i].second << "\n";
  }
  cout << "\n";
}
int main () {
  fill(dist, dist + 50, -INF);

  cin >> N >> SC >> DC >> M;
  for (int i = 0; i < M; ++i) {
    cin >> s >> d >> c;
    edges.push_back({{ s, d }, c });
  }


  for (int i = 0; i < N; ++i) {
    // cin >> v;
    cin >> earnings[i];
    // for (int j = 0; j < M; ++j) {
    //   if (edges[j].first.second == i) {
    //     edges[j].second -= v;
    //   }
    // }
  }

  dist[SC] = earnings[SC];
  for (int i = 0; i < N; ++i) {
    for (auto e : edges) {
      int from = e.first.first;
      int to = e.first.second;
      int cost = e.second;

      if (dist[from] == -INF) continue;
      if (dist[to] < earnings[to] + dist[from] - cost) {
        dist[to] = earnings[to] + dist[from] - cost;
      }
    }
  }

  // printE();
  // for (int i = 0; i < N; ++i) {
  //   cout << dist[i] << " " << " ";
  // }
  // cout << "\n";

  if (dist[DC] == -INF) {
    cout << "gg";
    return 0;
  }

  for (auto e : edges) {
    int from = e.first.first;
    int to = e.first.second;
    int cost = e.second;

    if (dist[from] == -INF) continue;
    if (dist[to] < earnings[to] + dist[from] - cost) { // renewed, cycle exists to negative infinite 
      cout << "Gee";
      return 0;
    }
  }

  // for (int i = 0; i < N; ++i) {
  //   cout << dist[i] << " " << " ";
  // }
  // cout << "\n";

  cout << dist[DC];

  return 0;
}