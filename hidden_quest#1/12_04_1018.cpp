#include <bits/stdc++.h>
using namespace std;

int N, M;
int b[50][50];
int res = 1'234'567'890;
int cb[8][8] = {
  {0,1,0,1,0,1,0,1},
  {1,0,1,0,1,0,1,0},
  {0,1,0,1,0,1,0,1},
  {1,0,1,0,1,0,1,0},
  {0,1,0,1,0,1,0,1},
  {1,0,1,0,1,0,1,0},
  {0,1,0,1,0,1,0,1},
  {1,0,1,0,1,0,1,0},
};

int main () {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < s.length(); ++j) {
      b[i][j] = s[j] == 'W' ? 0 : 1;
    }
  }

  // for (int i = 0; i < N; ++i) {
  //   for (int j = 0; j < M; ++j) {
  //     cout << b[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  for (int sy = 0; sy <= N - 8; ++sy) {
    for (int sx = 0; sx <= M - 8; ++sx) {
      int ac = 0; // method A count: start with W
      int bc = 0; // method B count: start with B
      for (int dy = 0; dy < 8; ++dy) {
        for (int dx = 0; dx < 8; ++dx) {
          if (b[sy + dy][sx + dx] == cb[dy][dx]) ac++;
          if (b[sy + dy][sx + dx] != cb[dy][dx]) bc++;
        }
      }
      res = min(res, ac);
      res = min(res, bc);
    }
  }
  cout << res;
  return 0;
}