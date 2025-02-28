// https://www.acmicpc.net/problem/17837
#include <bits/stdc++.h>
using namespace std;

struct Mal {
  int id;
  int d;
  int y;
  int x;
  Mal* u;
  Mal* o;
};

int N, K;
int bc[12][12];
Mal* mals[10];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

string visualDirection(int d) {
  if (d == 0) return "^";
  if (d == 1) return ">";
  if (d == 2) return "v";
  return "<"; // d == 3
}

int convertDirection(int in) { // 0: ^, 1: >, 2: v, 3: <
  if (in == 1) return 1;
  if (in == 2) return 3;
  if (in == 3) return 0;
  return 2; // in == 4
}

void remove(Mal* m) { // include all of the mal(piece, token)s over the m
  if (m->u != NULL) m->u->o = NULL;
}

Mal* findMalOn(int y, int x) {
  for (int i = 0; i < K; ++i) {
    Mal* target = mals[i];
    if (target->y == y && target->x == x && target->u == NULL) return target;
  }
  return NULL;
}

Mal* getTopMal(Mal* m) {
  if (m == NULL) return NULL;
  Mal* top = m;
  while (true) {
    if (top->o == NULL) break;
    top = top->o;
  }
  return top;
}

void move(Mal* m, int y, int x) {
  remove(m);

  Mal* foundMal = findMalOn(y, x);
  m->u = getTopMal(foundMal);
  if (m->u != NULL) m->u->o = m;

  // update coordinate
  Mal* top = m;
  while (top != NULL) {
    top->y = y;
    top->x = x;
    top = top->o;
  }
}

void reverse(Mal* m) {
  stack<Mal*> s;
  Mal* top = m;
  while (top != NULL) {
    s.push(top);
    top = top->o;
  }

  if (s.empty()) return;

  Mal* next = s.top();s.pop();
  next->u = m->u;
  if (next->u != NULL) {
    next->u->o = next;
  }
  while (!s.empty()) {
    next->o = s.top();s.pop();
    if(next->o != NULL) {
      next->o->u = next;
    }
    next = next->o;
  }
  m->o = NULL;
}

void pb() {
  cout << "==========\n";
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      string s("");
      Mal* top = findMalOn(i, j);
      while (top != NULL) {
        s.append(to_string(top->id));
        s.append(visualDirection(top->d));
        top = top->o;
      }
      printf("%d[%-10s] ", bc[i][j], s.c_str());
    }
    cout << "\n";
  }
}

// int main () {
//   K = 4;
//   Mal m0 = { 0, 0, 0, 0, NULL, NULL };
//   mals[0] = &m0;
//   Mal m1 = { 1, 0, 0, 1, NULL, NULL };
//   mals[1] = &m1;
//   Mal m2 = { 2, 0, 0, 0, NULL, NULL };
//   mals[2] = &m2;
//   Mal m3 = { 3, 0, 0, 0, NULL, NULL };
//   mals[3] = &m3;

//   m0.o = &m1;
//   m1.u = &m0;
//   m1.o = &m2;
//   m2.u = &m1;
//   m2.o = &m3;
//   m3.u = &m2;

//   // move(&m0, 0, 1);
//   // cout << m0.u->id << "\n";
//   reverse(&m1);
//   return 0;
// }

bool checkLen() {
  int maxCnt = 0;
  for (int i = 0; i < K; ++i) {
    int cnt = 0;
    Mal* top = mals[i];
    if (top->u != NULL) continue;
    while (top != NULL) {
      cnt++;
      top = top->o;
    }
    maxCnt = max(maxCnt, cnt);
  }
  // cout << "mc: " << maxCnt << "\n";
  if (maxCnt >= 4) {
    return true;
  }
  return false;
}

int main () {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> bc[i][j];
    }
  }

  for (int i = 0; i < K; ++i) {
    mals[i] = new Mal();
    mals[i]->id = i;
    cin >> mals[i]->y;
    mals[i]->y--;
    cin >> mals[i]->x;
    mals[i]->x--;
    cin >> mals[i]->d;
    mals[i]->d = convertDirection(mals[i]->d);
    mals[i]->u = NULL;
    mals[i]->o = NULL;
  }
  // pb();

  int turn = 0;
  while (true) {
    turn++;

    for (int i = 0; i < K; ++i) {
      Mal* m = mals[i];

      int y = m->y;
      int x = m->x;
      int ny = y+ dy[m->d];
      int nx = x+ dx[m->d];

      // printf("(%d,%d) -> (%d,%d)\n", y, x, ny, nx);

      if (ny < 0 || nx < 0 || ny >= N || nx >= N || bc[ny][nx] == 2) { // blue square or out of bounds
        m->d = (m->d + 2) % 4; // turn around;

        int nny = y + dy[m->d]; // ⚠️ nny = ny + dy[m->d] // (❌)
        int nnx = x + dx[m->d];
        if (nny < 0 || nnx < 0 || nny >= N || nnx >= N || bc[nny][nnx] == 2) {
          // pb();
          continue;
        }
        ny = nny;
        nx = nnx;
      }

      if (bc[ny][nx] == 0) { // white square
        move(m, ny, nx);
      }

      if (bc[ny][nx] == 1) { // red square
        move(m, ny, nx);
        reverse(m);
      }
      // pb();
      if (checkLen()) {
        cout << turn;
        return 0;
      }
    }

    if (turn > 1000) { // TODO temp
      cout << -1;
      return 0;
    }
  }
  return 0;
}