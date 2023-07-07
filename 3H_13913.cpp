// https://www.acmicpc.net/problem/13913
#include <bits/stdc++.h>
using namespace std;

int sip, bp; // subin's initial position, brother's position
const int M = 100'001;
int v[M]; // vistited
map<int, string> h;

void bfs() {
  queue<int> q;
  v[sip] = 1;
  h[sip] = to_string(sip);
  q.push(sip);

  while (q.size()) {
    int now = q.front();
    q.pop();

    for (int next : { now - 1, now + 1, now * 2 }) {
      if (next < 0 || next >= M) continue;
      if (v[next] == 0) {
        v[next] = v[now] + 1;
        h[next] = h[now] + " " + to_string(next);
        if (next == bp) return;
        q.push(next);
      }
    }
  }
}

int main () {
  cin >> sip >> bp;
  bfs();
  cout << v[bp] - 1 <<  "\n" << h[bp];
  return 0;
}