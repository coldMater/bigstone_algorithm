// https://www.acmicpc.net/problem/11657
#include <bits/stdc++.h>
using namespace std;

int N, M;
int A, B, C;
int INF = 987'654'321;
vector<pair<pair<int, int>, int>> buses;
int main () {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> A >> B >> C;
    buses.push_back({{ A, B }, C});
  }

  long long dist[N + 2]; // ⚠️ Time can be exceed the range of an integer
  dist[1] = 0;
  fill(dist + 2, dist + N + 1, INF);
  // for (int i = 1; i <= N; ++i) {
  //   cout << dist[i] << " ";
  // }
  // cout << "\n";
  for (int i = 0; i <= N - 1; ++i) {
    for (int j = 0; j < buses.size(); ++j) {
      int from = buses[j].first.first;
      int to = buses[j].first.second;
      int time = buses[j].second;
      // cout << "from, to, time: " << from << ", " << to << ", " << time << "\n";

      if (dist[from] == INF) continue;
      // cout << "dist[to]: " << dist[to] << ", dist[from]: " << dist[from] << ", time: " << time << "\n";
      if (dist[to] > dist[from] + time) {
        // cout << "updated!\n";
        dist[to] = dist[from] + time;

      }
    }
  }

  for (int i = 0; i < buses.size(); ++i) {
    int from = buses[i].first.first;
    int to = buses[i].first.second;
    int time = buses[i].second;

    if (dist[from] == INF) continue;
    if (dist[to] > dist[from] + time) {
      cout << -1;
      return 0;
    }
  }

  for (int i = 2; i <= N; ++i) {
    if (dist[i] == INF) cout << -1 << "\n";
    else cout << dist[i] << "\n";
  }
  return 0;
}