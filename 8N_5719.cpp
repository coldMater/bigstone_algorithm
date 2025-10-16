// https://www.acmicpc.net/problem/5719
#include <bits/stdc++.h>
using namespace std;

int N, M, S, D;
int U, V, P; // U: from, V: to, P: cost
int d[500];
int edges[500][500];
int INF = 987'654'321;
priority_queue<pair<int, int>> pq;

void printE() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (edges[i][j] == INF) cout << "X";
      else cout << edges[i][j];
      cout << "\t";
    }
    cout << "\n";
  }
}

void dijk(int start) {
  fill(d, d + 500, INF);
  d[start] = 0;
  pq.push({ 0, start });
  while (!pq.empty()) {
    int from = pq.top().second;
    int cost_org = -pq.top().first;
    pq.pop();

    for (int to = 0; to < N; ++to) {
      if (from == to) continue;
      int cost_next = cost_org + edges[from][to];
      if (d[to] > cost_next) {
        d[to] = cost_next;
        pq.push({ -cost_next, to });
      }
    }
  }
}

int main () {
  while (true) {
    cin >> N >> M; // N: number of vertices, M: number of edges
    if (N == 0 && M == 0) break;
    cin >> S >> D; // S: start, D: destination

    fill(&edges[0][0], &edges[0][0] + 500 * 500, INF);
    fill(d, d + 500, INF);
    for (int i = 0; i < M; ++i) {
      cin >> U >> V >> P;
      edges[U][V] = P;
    }

    // printE();

    dijk(S);

    // Remove edges that are part of any shortest path
    // ☠️ pain point: I couldn't come up with this myself
    queue<int> q;
    q.push(D);
    while (!q.empty()) {
      int to = q.front();
      q.pop();
      for (int from = 0; from < N; ++from) {
        if (from == to) continue;
        if (d[to] == d[from] + edges[from][to]) {
          q.push(from);
          edges[from][to] = INF;
          // cout << "Node on shortest path: " << from << "\n";
        }
      }
    }

    dijk(S);
    if (d[D] == INF) cout << "-1" << "\n";
    else cout << d[D] << "\n";
  }

  return 0;
}