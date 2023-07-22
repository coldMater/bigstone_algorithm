// https://www.acmicpc.net/problem/17071
#include <bits/stdc++.h>
using namespace std;

int sip, bp; // subin's initial position, brother's position
const int M = 500'001; // MAX
int visited[M];
int now;
int bfs () { // brother's present position
  queue<int> q;
  q.push(sip);
  visited[sip] = 1;

  int t = 0;
  while (!q.empty()) {
    int qSize = q.size();
    for (int i = 0; i < qSize; ++i) {
      int prev = q.front();
      q.pop();
      if (prev == bp) return t;

      for (int next : { prev - 1, prev + 1, prev * 2 }) {
        if (visited[bp] != 0 && (t - visited[bp] - 1) % 2 == 0) {
          return t;
        }
        if (next < 0 || next >= M) continue;
        if (visited[next] != 0) continue;
        visited[next] = visited[prev] + 1;
        if (visited[bp] != 0 && (t - visited[bp] - 1) % 2 == 0) {
          return t;
        }
        q.push(next);
      }
    }
    t++;
    bp = bp + t;
    if (bp >= M) return -1;
  }
  return -1;
}

int main () {
  cin >> sip >> bp;

  cout << bfs();

  return 0;
}
