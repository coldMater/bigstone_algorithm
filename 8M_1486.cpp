// https://www.acmicpc.net/problem/1486
#include <bits/stdc++.h>
using namespace std;

int N, M, T, D; // T: height limit, D: day time
int m[25][25];
int d[25][25]; // meaning of d[i][j]: time cost from (0,0) to (i,j)
int INF = 1'234'567'890;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

priority_queue<pair<int, pair<int, int>>> pq;

void printArr(int arr[25][25]) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      printf("%10d ", arr[i][j]);
    }
    cout << "\n";
  }
  cout << "---\n";
}

int main () {
  cin >> N >> M >> T >> D;

  for (int i = 0; i < N; ++i) {
    string t;
    cin >> t;
    for (int j = 0; j < M; ++j) {
      char c = t[j];
      if ('A' <= c && c <= 'Z') m[i][j] = c - 'A';
      if ('a' <= c && c <= 'z') m[i][j] = c - 'a' + 26;
    }
  }

  fill(&d[0][0], &d[0][0] + 25 * 25, INF);

  d[0][0] = 0;
  pq.push({ 0, { 0, 0 } });

  while (!pq.empty()) {
    int y = pq.top().second.first;
    int x = pq.top().second.second;
    pq.pop();
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

      int h_here = m[y][x];
      int h_there = m[ny][nx];
      if (abs(h_there - h_here) > T) continue; // ⚠️ The same applies when going down.

      int time;
      if (h_there <= h_here) time = 1; // The height difference is 1 or less: it takes 1 unit of time
      else time = pow(h_there - h_here, 2); // The height difference is greater than 1: it takes square of difference

      int time_dijkstra_prev = d[ny][nx];
      int time_dijkstra_new = d[y][x] + time;
      if (time_dijkstra_new < time_dijkstra_prev) {
        d[ny][nx] = time_dijkstra_new;
        pq.push({ -time_dijkstra_new, { ny, nx } });
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (d[i][j] > D) continue;
      int d2[25][25];
      fill(&d2[0][0], &d2[0][0] + 25 * 25, INF);
      d2[i][j] = 0;
      priority_queue<pair<int, pair<int, int>>> pq2;
      pq2.push({ 0, { i, j } });
      while (!pq2.empty()) {
        int y = pq2.top().second.first;
        int x = pq2.top().second.second;
        pq2.pop();
        for (int k = 0; k < 4; ++k) {
          int ny = y + dy[k];
          int nx = x + dx[k];
          if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

          int h_here = m[y][x];
          int h_there = m[ny][nx];
          if (abs(h_there - h_here) > T) continue; // ⚠️ The same applies when going down.

          int time;
          if (h_there <= h_here) time = 1; // The height difference is 1 or less: it takes 1 unit of time
          else time = pow(h_there - h_here, 2); // The height difference is greater than 1: it takes square of difference

          int time_dijkstra_prev = d2[ny][nx];
          int time_dijkstra_new = d2[y][x] + time;
          if (time_dijkstra_new < time_dijkstra_prev) {
            d2[ny][nx] = time_dijkstra_new;
            pq2.push({ -time_dijkstra_new, { ny, nx } });
          }
        }
      }
      // printArr(d2);

      int time_from_hotel = d[i][j];
      int time_to_hotel = d2[0][0];
      int time_total = time_from_hotel + time_to_hotel;
      if (time_from_hotel + time_to_hotel > D) continue;

      ans = max(ans, m[i][j]);
    }
  }

  cout << ans;

  return 0;
}


  // for (int i = 0; i < N; ++i) {
  //   for (int j = 0; j < M; ++j) {
  //     printf("%3d", m[i][j]);
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";