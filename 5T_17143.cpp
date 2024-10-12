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
shark b[101][101];
shark nb[101][101]; // next board

void drawBoard () {
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j ) {
      cout << "[";
      if (b[i][j].idx > 0) {
        cout << char(b[i][j].idx + 65 - 1) << (b[i][j].d == 4 ? "<" : b[i][j].d == 3 ? ">" : b[i][j].d == 1 ? "^" : "v");
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
    // int dedup = s->s;
    while (dedup-- > 0) {
      if (s->d == 3) {
        s->c += 1; // when right
        if (s->c > C) { s->c = C - 1; s->d = 4; continue; } // turn to left
      }
      if (s->d == 4) {
        s->c -= 1; // when left
        if (s->c < 1) { s->c = 2; s->d = 3; continue; } // turn to right
      }
    }
  }
  if (s->d == 1 || s->d == 2) {
    int dedup = s->s % ((R - 1) * 2);
    // int dedup = s->s;
    while (dedup-- > 0) {
      if (s->d == 2) {
        s->r += 1; // when down
        if (s->r > R) { s->r = R - 1; s->d = 1; continue; } // turn to up
      }
      if (s->d == 1) {
        s->r -= 1; // when up
        if (s->r < 1) { s->r = 2; s->d = 2; continue; } // turn to down
      }
    }
  }
  // cout << "\n";
}

void moveSharks () {
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      shark s = b[i][j];
      if (s.idx == 0) continue;
      moveShark(&s);
      if (nb[s.r][s.c].idx > 0) {
        // cout << "Battle! " << nb[s.r][s.c].idx << "(" << nb[s.r][s.c].z << ")" << " VS " << s.idx << "(" << s.z << ")" << "\n";
        if (nb[s.r][s.c].z < s.z) {
          nb[s.r][s.c] = s;
        }
      } else {
        nb[s.r][s.c] = s;
      }
    }
  }
}

int main () {
  cin >> R >> C >> M;

  for (int i = 0; i < M; ++i) {
    shark s;
    cin >> s.r >> s.c >> s.s >> s.d >> s.z;
    s.idx = i + 1; // assigning number to each shark (0: none of shark exist)
    b[s.r][s.c] = s;
  }


  int tw = 0; // caught shark's total weight
  for (int fm = 1; fm <= C; ++fm) { // fm: fisherman's position (equal to day count)
    // cout << "day: " << fm << "\n";
    // drawBoard();
    for (int i = 1; i <= R; ++i) {
      if (b[i][fm].idx > 0) {
        tw += b[i][fm].z;
        b[i][fm].idx = 0; // death handling
        break;
      }
    }

    // drawBoard();
    moveSharks();
    memcpy(b, nb, sizeof(b));
    memset(nb, 0, sizeof(b));
    // drawBoard();
  }

  cout << tw;

  return 0;
}