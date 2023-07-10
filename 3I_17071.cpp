// https://www.acmicpc.net/problem/17071
#include <bits/stdc++.h>
using namespace std;

int sip, bp; // subin's initial position, brother's position
const int M = 500'001; // MAX
int visited[M];
int now, bpp;
void bfs () {
  queue<int> q;
  q.push(sip);
  visited[sip] = 1;

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    for (int next : { now - 1, now + 1, now * 2 }) {
      if (next < 0 || next >= M) continue;
      visited[next] = visited[now] + 1;
      bpp = bp + (visited[now] + 1) * visited[now] / 2; // brother's present position
      if (bpp >= M) {
        bpp = -1;
        return;
      }
      if (bpp == next) {
        return;
      }
      q.push(next);
    }
  }
}

int main () {
  cin >> sip >> bp;

  if (sip == bp) {
    cout << 0;
    return 0;
  }

  bfs();
  cout << visited[bpp] - 1;

  return 0;
}
