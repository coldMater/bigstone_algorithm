// https://www.acmicpc.net/problem/17071
#include <bits/stdc++.h>
using namespace std;

int sip, bp; // subin's initial position, brother's position
const int M = 500'001; // MAX
int visited[M];
int now;
void bfs () { // brother's present position
  queue<int> q;
  q.push(sip);
  visited[sip] = 1;

  while (!q.empty()) {
    int prev = q.front();
    q.pop();

    for (int next : { prev - 1, prev + 1, prev * 2 }) {
      if (next < 0 || next >= M) continue;
      if (visited[next] != 0) continue;
      visited[next] = visited[prev] + 1;
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
  int t = 0;
  int min = 987654321;
  int minT = 0;
  while(true) {
    t++;
    bp = bp + t;
    if (bp >= M) {
      break;
    }
    if ((visited[bp] - 1 - t) % 2 == 0) {
      if (min > (visited[bp] - 1)) { 
        min = visited[bp] - 1;
        minT = t;
      }
      if (visited[bp] - 1 == t) {
        cout << t;
        return 0;
      }
    }
    // cout << visited[bp] - 1 << "\t" << bp << "\t" << t << " " << minT << "\t" << (q ? " MIN" : " ") << "\n";
  }
  if (minT == 0) {
    cout << "-1";
  } else {
    cout << minT;
  }

  return 0;
}
