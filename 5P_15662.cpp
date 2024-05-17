// https://www.acmicpc.net/problem/15662
#include <bits/stdc++.h>
using namespace std;

int T, K;
deque<int> g[1001]; // gears
vector<pair<int, int>> r; // rotates

void printList(deque<int> g) {
  for (int i : g) {
    cout << i;
  }
  cout << "\n";
}

void rotateList(deque<int>& l, int direction) { // ⚠️ `list<int> l` vs `list<int>& l` as parameter type 
  if (direction == 1) {
    int temp = l.back();
    l.pop_back();
    l.push_front(temp);
  }

  if (direction == -1) {
    int temp = l.front();
    l.pop_front();
    l.push_back(temp);
  }
}

void toRight (int gn, int d) { // gear, direction
  if (gn > T) return;
  if (gn - 1 >= 1 && g[gn - 1][2] == g[gn][6]) return;
  toRight(gn + 1, d == 1 ? -1 : 1);
  rotateList(g[gn], d);
}

void toLeft (int gn, int d) {
  if (gn < 1) return; 
  if (gn + 1 <= T && g[gn][2] == g[gn + 1][6]) return;
  toLeft(gn - 1, d == 1 ? -1 : 1);
  rotateList(g[gn], d);
}

int main () {
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    string gs; // gear as string
    cin >> gs;
    for (char c : gs) {
      g[i].push_back(c - '0');
    }
  }

  cin >> K;
  for (int i = 0; i < K; ++i) {
    int gn, d; // number of gear, direction
    cin >> gn >> d;

    r.push_back({ gn, d });
  }

  for (int i = 0; i < K; ++i) {
    int gn, d;
    gn = r[i].first;
    d = r[i].second;

    toRight(gn + 1, d == 1 ? - 1 : 1);
    toLeft(gn - 1, d == 1 ? - 1 : 1);
    rotateList(g[gn], d);
  }

  int res = 0;
  for (int i = 1; i <= T; ++i) {
    res += g[i][0];
    // printList(g[i]);
  }
  cout << res;

  return 0;
}