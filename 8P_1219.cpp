// https://www.acmicpc.net/problem/1219
#include <bits/stdc++.h>
using namespace std;

int N, SC, DC, M;
int s, d, c, v;
vector<pair<pair<int, int>, int>> edges;
int INF = 987'654'321;
long long dist[50];
int earnings[50];
int visited[50];
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

  queue<int> updates;
  for (auto e : edges) {
    int from = e.first.first;
    int to = e.first.second;
    int cost = e.second;

    if (dist[from] == -INF) continue;
    if (dist[to] < earnings[to] + dist[from] - cost) { // renewed, cycle exists to negative infinite 
      updates.push(from);
    }
  }

  while (!updates.empty()) {
    int here = updates.front(); updates.pop();
    for (auto e : edges) {
      int from = e.first.first;
      int to = e.first.second;
      if (from != here) continue;

      if (to == DC) { // `if (to == d) {` ⚠️ Incorrect code – It took quite a lot of time to find this mistake.
        cout << "Gee";
        return 0;
      }
      if (visited[to] == 1) continue;
      updates.push(to);
      visited[to] = 1;
    }
  }

  cout << dist[DC];
  // for (int i = 0; i < N; ++i) {
  //   cout << dist[i] << " " << " ";
  // }
  // cout << "\n";

  return 0;
}