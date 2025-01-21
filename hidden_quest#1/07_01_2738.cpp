#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[100][100];
int b[100][100];
int main () {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> b[i][j];
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << a[i][j] + b[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}