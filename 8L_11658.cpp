// https://www.acmicpc.net/problem/11658
#include <bits/stdc++.h>
using namespace std;

int N, M;
int fenwick_tree[1025][1025];
int m[1025][1025];

void update (int y, int x, int v) {
  while (x <= 1024) {
    fenwick_tree[y][x] += v;
    x += x & -x;
  }
}

int query (int y, int x) {
  int sum = 0;
  while (x > 0) {
    sum += fenwick_tree[y][x];
    x -= x & -x;
  }
  return sum;
}

int main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> N >> M;
  for (int x = 1;  x <= N; ++x) {
    for (int y = 1; y <= N; ++y) {
      int temp;
      cin >> temp;
      m[y][x] = temp;
      update(y, x, temp);
    }
  }
  for (int i = 0; i < M; ++i) {
    int w;
    cin >> w;
    if (w == 0) {
      int x, y, c;
      cin >> x >> y >> c;
      update(y, x, c - m[y][x]);
      m[y][x] = c;
    }
    if (w == 1) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      // cout << "x1,y1: " << x1 << ", " << y1 << ", x2,y2: " << x2 << ", " << y2 << "\n";
      int sum = 0;
      for (int y = y1; y <= y2; ++y) {
        int t = query(y, x2) - query(y, x1 - 1);
        // cout << t << "\n";
        sum += t;
      }
      cout << sum << "\n";
    }
  }
  return 0;
}