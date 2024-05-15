// https://www.acmicpc.net/problem/17406
#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int m[51][51];
tuple<int, int, int> r[6];
int test[3] = { 1, 2, 3};
void pb (int target[51][51]) {
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      cout << target[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void swap (int a, int b) {
  auto temp = r[a];
  r[a] = r[b];
  r[b] = temp;
}

// get value of matrix
int getMin (int target[51][51]) {
  int mm = 987654321; // minimum
  for (int i = 1; i <= N; ++i) {
    int sum = 0;
    for (int j = 1; j <= M; ++j) {
      sum += target[i][j];
    }
    mm = min(sum, mm);
  }
  return mm;
}



// void tg (int d) {
//   if (d == 3) {
//     for (int r : test) {
//       cout << r << " ";
//     }
//     cout << "\n";
//   }
//   for (int i = d; i < 3; ++i) {
//     swap(i, d);
//     tg(d + 1);
//     swap(i, d);
//   }
// } // test go

void rotate (int target[51][51], tuple<int,int,int>& o) {
  // cout << "rotate: " << get<0>(o) << get<1>(o) << get<2>(o) << "\n";
  int cy = get<0>(o); // center Y
  int cx = get<1>(o); // center X
  int s =  get<2>(o);// s (problem)

  for (int d = 1; d <= s; ++d) {
    int y, x;
    int sy, ey, sx, ex;

    int topRightCorner = target[cy - d][cx + d];

    // top line
    y = cy - d;
    sx = cx - d; // start x
    ex = cx + d;// end y

    for (x = ex; x >= sx + 1; --x) {
      target[y][x] = target[y][x - 1];
    }

    // left line
    x = cx - d;
    sy = cy - d;
    ey = cy + d;
    for (y = sy; y <= ey - 1; ++y) {
      target[y][x] = target[y + 1][x];
    }

    // bottom line
    y = cy + d;
    sx = cx - d;
    ex = cx + d;
    for (x = sx; x <= ex - 1; ++x) {
      target[y][x] = target[y][x + 1];
    }

    // right line
    x = cx + d;
    sy = cy - d;
    ey = cy + d;
    for (y = ey; y >= sy + 1; --y) {
      target[y][x] = target[y - 1][x];
    }

    target[cy - d + 1][cx + d] = topRightCorner;
    // pb();
  }
}

int go(int d) {
  if (d == K) {
    int t[51][51];
    memcpy(t, m, sizeof(m));
    for (int i = 0; i < K; ++i) {
      rotate(t, r[i]);
    }
    // pb(t);
    return getMin(t);
  }

  int mm = 987654321;
  for (int i = d; i < K; ++i) {
    swap(i, d);
    mm = min(go(d + 1), mm);
    swap(i, d);
  }
  return mm;
}

int main () {
  cin >> N >> M >> K;

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      int v;
      cin >> v;
      m[i][j] = v;
    }
  }

  for (int i = 0; i < K; ++i) {
    int f, s, t;
    cin >> f >> s >> t;
    r[i] = { f, s, t };
  }

  cout << go(0);

  return 0;
}
