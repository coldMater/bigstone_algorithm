// https://www.acmicpc.net/problem/15685
#include<bits/stdc++.h>
using namespace std;

struct curveSeed {
  int x;
  int y;
  int d; // direction: (0: >, 1: ^, 2: <, 3: v)
  int g; // generation
};

struct point {
  int x;
  int y;
};

struct line {
  point s;
  point e;
};

struct boardForDraw {
  bool h[101][101];
  bool v[101][101];
};

bool board[101][101];

line getLineFromCurveSeed (curveSeed cs) {
  if (cs.d == 0) return { { cs.x, cs.y }, { cs.x + 1, cs.y } }; // >
  if (cs.d == 1) return { { cs.x, cs.y }, { cs.x, cs.y - 1 } }; // ^
  if (cs.d == 2) return { { cs.x, cs.y }, { cs.x - 1, cs.y } }; // <
  if (cs.d == 3) return { { cs.x, cs.y }, { cs.x, cs.y + 1 } }; // v
  throw "invalid direction";
};

int drawBoard (boardForDraw brd) {
  int L = 100; // length
  cout << "    ";
  for (int i = 0; i <= L; ++i) { // tick
    printf("%-4d", i);
  }
  cout << "\n";
  for (int i = 0; i < L; ++i) {
    printf("%3d ", i);
    for (int j = 0; j < L; ++j) {
      cout << "+";
      if (brd.h[j][i]) {
        cout << "---"; // horizontal line
      } else {
        cout << "   "; // horizontal line
      }
    }
    cout << "+";
    cout << "\n";
    cout << "    ";
    for (int j = 0; j < L; ++j) {
      if (brd.v[j][i]) {
        cout << "|"; // vertical line
      } else {
        cout << " "; // vertical line
      }
      cout << "   ";
    }
    // right border
    if (brd.v[L][i]) {
      cout << "|"; // vertical line
    } else {
      cout << " "; // vertical line
    }
    cout << "\n";
  }
  // bottom border first lineA
  printf("%3d ", L);
  for (int j = 0; j < L; ++j) { // bottom border
    cout << "+";
    if (brd.h[j][L]) {
      cout << "---"; // horizontal line
    } else {
      cout << "   "; // horizontal line
    }
  }
  cout << "+"; // right border
  return 0;
}

void convertToBoard(vector<vector<line>> dcs) { // dragon curves
  for (vector<line> ls : dcs) {
    for (line l : ls) {
      board[l.e.x][l.e.y] = true;
      board[l.s.x][l.s.y] = true;
    }
  }
}

int countBoard () {
  int cnt = 0;
  for (int y = 0; y < 100; ++y) {
    for (int x = 0; x < 100; ++x) {
      if (board[x][y] && board[x + 1][y] && board[x][y + 1] && board[x + 1][y + 1]) cnt++;
    }
  }

  return cnt;
}

int N;
curveSeed cs[20]; // curve seeds
vector<vector<line>> dcs[20]; // dragon curve

// int afterRotate(int d) { // direction after rotate (reverse)
//   if (d == 0) return 1; // > to ^ 
//   if (d == 1) return 2; // ^ to <
//   if (d == 2) return 3; // < to v
//   if (d == 3) return 0; // v to >
// }

point rotate(point t, point p) { // target, pivot
  point d = { t.x - p.x, t.y - p.y }; // diff
  // printf("d: (%d,%d)\n", t.x - p.x, t.y - p.x);
  point r = { -d.y, d.x }; // rotated
  // printf("r:(%d,%d)\n", p.x + r.x, p.y + r.y);
  // printf("res:(%d,%d)\n", p.x + r.x, p.y + r.y);
  return { p.x + r.x, p.y + r.y };
}

line rotateLine(line t, point p) {
  return { rotate(t.s, p), rotate(t.e, p) };
}

void printEveryLineInfo(vector<line> v) {
  for (line l : v) {
    printf("(%d,%d) -> (%d,%d)\n", l.s.x, l.s.y, l.e.x, l.e.y);
  }
  cout << "\n";
}

// int main() {
//   // point p = { 3, 1 };
//   // point pv = { 0, 0 };
//   // point rotated = rotate(p, pv);

//   line l = { { 4, 2 }, { 4, 1 } };
//   line rotated = rotateLine(l, { 4, 1} );

//   vector<line> t;
//   t.push_back(rotated);
//   printEveryLineInfo(t);

//   return 0;
// }
boardForDraw convertToDrawBoard(vector<vector<line>> dcs) { // dragon curves
  boardForDraw brd;
  memset(&brd, 0, sizeof(brd));
  for (vector<line> ls : dcs) {
    for (line l : ls) {
      int dx = l.e.x - l.s.x;
      int dy = l.e.y - l.s.y;
      if (dx == 1) {
        brd.h[l.s.x][l.s.y] = true;
        continue;
      }
      if (dx == -1) {
        brd.h[l.e.x][l.e.y] = true;
        continue;
      }
      if (dy == 1) {
        brd.v[l.s.x][l.s.y] = true;
        continue;
      }
      if (dy == -1) {
        brd.v[l.e.x][l.e.y] = true;
        continue;
      }
      // printf("invalid: (%d,%d) -> (%d,%d) -- dx: %d, dy: %d \n", l.s.x, l.s.y, l.e.x, l.e.y, dx, dy);
    }
  }
  return brd;
}

vector<vector<line>> dcv; // dc vector;
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> cs[i].x >> cs[i].y >> cs[i].d >> cs[i].g;
  }

  
  for (int i = 0; i < N; ++ i) {
    curveSeed c = cs[i]; // as arguments when implement function

    line f = getLineFromCurveSeed(c); // first line

    int gen = 0;
    vector<line> ll;
    ll.push_back(f);
    while (++gen <= c.g) {
      // cout << "gen" << gen << "\n";

      int pivot = ll.size() - 1;
      // printf("pivot index: %d, end: (%d, %d)\n", pivot, ll[pivot].e.x, ll[pivot].e.y);
      for (int i = pivot; i >= 0; --i) {
        ll.push_back(rotateLine(ll[i], gen == 1 ? ll[pivot].e : ll[pivot].s)); // only at first generation end point of line used as pivot
      }
    }
    dcv.push_back(ll);
  }
  // printEveryLineInfo(ll);
  // convertToDrawBoard(ll);
  convertToBoard(dcv);
  cout << countBoard();

  return 0;
}