// https://www.acmicpc.net/problem/3190
#include <bits/stdc++.h>
using namespace std;

int N, K, L;
int t = 0;
int d = 0; // 0: right, 1: down, 2: left, 3: top
vector<pair<int,int>> ap; // position of apples
int m[100][100];
map<int, char> cm; // control map
const int APPLE = 6;
const int RIGHT = 0;
const int DOWN = 1;
const int LEFT = 2;
const int UP = 3;
vector<pair<int,int>> s; // snake

void pb (pair<int, int> head) { // print board
  cout << t << " d:" << d << "\n";
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (head.first == i && head.second == j) {
        cout << 'X' << " ";
        continue;
      }
      bool is = false; // is snake position?
      for (int k = 0; k < s.size(); ++k) {
        if (s[k].first == i && s[k].second == j) {
          is = true;
          break;
        }
      }
      if (is) {
        cout << '+' << " ";
      } else {
        cout << m[i][j] << " ";
      }
    }
    cout << "\n";
  }
  cout << "\n";
}

int main () {
  s.push_back({ 1, 1 });
  cin >> N;
  cin >> K;

  for (int i = 0; i < K; ++i) {
    int y, x;
    cin >> y >> x;
    m[y][x] = APPLE;
  }

  cin >> L;

  for (int i = 0; i < L; ++i) {
    int X;
    char C;
    cin >> X >> C;
    cm.insert({ X, C });
  }

  while (true) {
    t++;
    int hy, hx;
    tie(hy, hx) = s.back();

    // sticking out head
    int ny;
    int nx;
    if (d == RIGHT) {
      ny = hy;
      nx = hx + 1;
    } else if (d == DOWN) {
      ny = hy + 1;
      nx = hx;
    } else if (d == LEFT) {
      ny = hy;
      nx = hx - 1;
    } else if (d == UP) {
      ny = hy - 1;
      nx = hx;
    }
    
    // pb({ny, nx});

    // end condition #1: hit the wall
    if (t == 13) {
      // cout << "ny: " << ny << ", nx: " << nx << "\n";

    }
    if (nx > N || ny > N || nx <= 0 || ny <= 0) {
      // cout << "t = " << t <<  ", game end!" << "\n";
      break;
    }

    // end condition #2: hit snake's body
    bool hitBody = false;
    for (int i = 0; i < s.size(); ++i) {
      int sy, sx;
      tie(sy, sx) = s[i];
      if (sy == ny && sx == nx) {
        // cout << "t = " << t <<  ", game end!" << "\n";
        hitBody = true;
      }
    }
    if (hitBody) {
      break;
    }

    s.push_back({ ny, nx });

    // folding tail
    if (m[ny][nx] == APPLE) {
      m[ny][nx] = 0;
      // do nothing
    } else {
      s.erase(s.begin());
    }

    // pb({-1, -1});

    // rotate direction
    auto control = cm.find(t);
    if (control != cm.end()) {
      if (control->second == 'L') {
        d -= 1;
        if (d < 0) d = 3;
      } else { // 'R'
        d += 1;
        if (d > 3) d = 0;
      }
      // cout << "direction changed!" << "\n";
    }

    // end condition

    // cout << "=======\n";
  }
  cout << t;

  return 0;
}