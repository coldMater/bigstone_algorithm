// https://www.acmicpc.net/problem/17143
#include <bits/stdc++.h>
using namespace std;

struct shark {
  int idx; // index
  int r; // row
  int c; // col
  int s; // speed
  int d; // direction (1: up, 2: down, 3: right, 4: left)
  int z; // size of shark
};


int R, C, M;
// vector<shark> ss; // sharks;
vector<shark> b[101][101];
vector<shark> nb[101][101]; // next board

void copyAndReset () {
  for (int i = 1; i <= R; ++i) {
    for ( int j = 1; j <= C; ++j) {
      b[i][j] = nb[i][j];
      nb[i][j].clear();
    }
  }
}

void drawBoard () {
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j ) {
      cout << "[";
      for (shark s : b[i][j]) {
        cout << s.idx << (s.d == 4 ? "<" : s.d == 3 ? ">" : s.d == 1 ? "^" : "v");
      }
      cout << "]\t";
    }
    cout << "\n";
  }
  cout << "\n";
}

void drawNextBoard () {
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j ) {
      cout << "[";
      for (shark s : nb[i][j]) {
        cout << s.idx << (s.d == 4 ? "<" : s.d == 3 ? ">" : s.d == 1 ? "^" : "v");
      }
      cout << "]\t";
    }
    cout << "\n";
  }
  cout << "\n";
}

void moveShark (shark* s) {
  // cout << "idx: " << s->idx << ", speed: " << s->s << "\n";
  if (s->d == 3 || s->d == 4) {
    int dedup = s->s % ((C - 1) * 2);
    while (dedup-- > 0) {
      if (s->d == 3) {
        s->c += 1; // when right
        // cout << s->c << "->";
        if (s->c == C) { s->d = 4; continue; } // turn to left
      }
      if (s->d == 4) {
        s->c -= 1; // when left
        // cout << s->c << "->";
        if (s->c == 1) { s->d = 3; continue; } // turn to right
      }
    }
  }
  if (s->d == 1 || s->d == 2) {
    int dedup = s->s % ((R - 1) * 2);
    while (dedup-- > 0) {
      if (s->d == 2) {
        s->r += 1; // when down
        // cout << s->r << "->";
        if (s->r == R) { s->d = 1; continue; } // turn to up
      }
      if (s->d == 1) {
        s->r -= 1; // when up
        // cout << s->r << "->";
        if (s->r == 1) { s->d = 2; continue; } // turn to down
      }
    }
  }
  // cout << "\n";
}

void moveSharks () {
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      for (shark s : b[i][j]) {
        moveShark(&s);
        nb[s.r][s.c].push_back(s);
      }
    }
  }
}

void battleSharks () {
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      int sc = nb[i][j].size(); // shark count
      if (sc <= 1) continue;
      shark largestShark = nb[i][j][0];
      for (int k = 1; k < sc; ++k) {
        if (largestShark.z < nb[i][j][k].z) {
          largestShark = nb[i][j][k];
        }
      }
      nb[i][j].clear();
      nb[i][j].push_back(largestShark);
    }
  }
}

int main () {
  cin >> R >> C >> M;

  for (int i = 0; i < M; ++i) {
    shark s;
    cin >> s.r >> s.c >> s.s >> s.d >> s.z;
    s.idx = i;
    b[s.r][s.c].push_back(s);
  }

  int tw = 0; // caught shark's total weight
  for (int fm = 1; fm <= C; ++fm) { // fisherman's position (equal to day count)
    for (int i = 1; i <= R; ++i) {
      if (b[i][fm].size()) {
        tw += b[i][fm][0].z;
        b[i][fm].clear();
        break;
      }
    }


    // cout << "day: " << fm << "\n";
    // drawBoard();
    moveSharks();
    // drawNextBoard();
    battleSharks();
    // drawNextBoard();
    copyAndReset();
  }

  cout << tw;

  return 0;
}