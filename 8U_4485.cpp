// https://www.acmicpc.net/problem/4485
#include <bits/stdc++.h>
using namespace std;

int N;
int m[125][125];
int dy[4] = { -1 , 0, 1, 0};
int dx[4] = { 0, 1, 0, -1 };
int dist[125][125];
int INF = 987'654'321;
int problem_num = 1;
int main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (true) {
    cin >> N;
    if (N == 0) break;

    fill(&dist[0][0], &dist[0][0] + 125 * 125, INF);

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cin >> m[i][j];
      }
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({ m[0][0], { 0, 0 } });
    dist[0][0] = m[0][0];

    while(!pq.empty()) {
      auto now = pq.top(); pq.pop();
      int c = now.first;
      int y = now.second.first;
      int x = now.second.second;

      // if (c != dist[y][x]) continue;
      for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

        if (dist[ny][nx] > c + m[ny][nx]) {
          dist[ny][nx] = c + m[ny][nx];
          pq.push({ c + m[ny][nx], { ny, nx }});
        }
      }
    }

    cout << "Problem " << problem_num++ << ": " << dist[N - 1][N - 1] << "\n";
  }

  return 0;
}
