// https://www.acmicpc.net/problem/17406
#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int m[51][51];
tuple<int, int, int> r[6];
int res = 987654321;
void pb () {
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      cout << m[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
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

  // pb();

  //rotate
  for (int i = 0; i < K; ++i) {
    int cy = get<0>(r[i]); // center Y
    int cx = get<1>(r[i]); // center X
    int s =  get<2>(r[i]);// s (problem)

    for (int d = 1; d <= s; ++d) {
      int y, x;
      int sy, ey, sx, ex;

      int topRightCorner = m[cy - d][cx + d];

      // top line
      y = cy - d;
      sx = cx - d; // start x
      ex = cx + d;// end y

      for (x = ex; x >= sx + 1; --x) {
        m[y][x] = m[y][x - 1];
      }

      // left line
      x = cx - d;
      sy = cy - d;
      ey = cy + d;
      for (y = sy; y <= ey - 1; ++y) {
        m[y][x] = m[y + 1][x];
      }

      // bottom line
      y = cy + d;
      sx = cx - d;
      ex = cx + d;
      for (x = sx; x <= ex - 1; ++x) {
        m[y][x] = m[y][x + 1];
      }

      // right line
      x = cx + d;
      sy = cy - d;
      ey = cy + d;
      for (y = ey; y >= sy + 1; --y) {
        m[y][x] = m[y - 1][x];
      }

      m[cy - d + 1][cx + d] = topRightCorner;
      pb();
    }
  }

  // get value of matrix
  for (int i = 1; i <= N; ++i) {
    int sum = 0;
    for (int j = 1; j <= M; ++j) {
      sum += m[i][j];
    }
    cout << sum << "\n";
    res = min(sum, res);
  }

  cout << res;

  return 0;
}
