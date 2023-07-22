// https://www.acmicpc.net/problem/17071
#include <bits/stdc++.h>
using namespace std;

int sip, bp; // subin's initial position, brother's position
const int M = 500'001; // MAX
int visited[2][M];
int now;
int bfs () { // brother's present position
  queue<int> q;
  q.push(sip);
  visited[0][sip] = 1;

  int t = 0;
  while (!q.empty()) {
    t++;
    bp = bp + t;
    if (bp >= M) return -1;
    int qSize = q.size();
    for (int i = 0; i < qSize; ++i) {
      int prev = q.front();
      q.pop();

      for (int next : { prev - 1, prev + 1, prev * 2 }) {
        if (next < 0 || next >= M) continue;
        if (visited[t % 2][next] != 0) continue;
        visited[t % 2][next] = visited[(t + 1) % 2][prev] + 1;
        if (visited[t % 2][bp] != 0) {
          return t;
        }
        q.push(next);
      }
    }
  }
  return -1;
}

int main () {
  cin >> sip >> bp;

  if (sip == bp) {
    cout << 0;
    return 0;
  }

  cout << bfs();

  return 0;
}
