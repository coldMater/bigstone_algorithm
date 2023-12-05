// https://www.acmicpc.net/problem/14391
#include <bits/stdc++.h>
using namespace std;

int N, M, n;
char m[4][4];
int mr;
string l;
int main () {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> l;
    for (int j = 0; j < M; ++j) {
      m[i][j] = l[j];
      // cout << m[i][j] << " ";
    }
    // cout << "\n";
  }

  for (int i = 0; i < (1 << (N*M)); ++i) {
    int result = 0;
    // horizontal check
    // cout << "i: " << i << "\n";
    for (int y = 0; y < N; ++y) {
      string s = "";
      for (int x = 0; x < M; ++x) {
        if (i & 1 << (y * M + x)) {
          s += m[y][x];
          // cout << "y: " << y << ", x: " << x << ", s: " << s <<   "\n";
        } else {
          if (s != "") {
            result += stoi(s);
            s = "";
          }
        }
      }
      if (s != "") {
        // cout << s << "\n";
        result += stoi(s);
      }
    }

    // vertical check
    for (int x = 0; x < M; ++x) {
      string s = "";
      for (int y = 0; y < N; ++y) {
        if ((i & 1 << (y * M + x)) == 0) {
          s += m[y][x];
          // cout << s << "\n";
        } else {
          if (s != "") {
            result += stoi(s);
            s = "";
          }
        }
      }
      if (s != "") {
        // cout << s << "\n";
        result += stoi(s);
      }
    }

    mr = max(result, mr);
  }

  cout << mr;
  return 0;
}