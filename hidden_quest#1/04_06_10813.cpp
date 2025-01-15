// https://www.acmicpc.net/problem/10813
#include <bits/stdc++.h>
using namespace std;

int N, M;
int b[100]; // baskets
int i, j, temp;
int main () {
  cin >> N >> M;
  for (int x = 0; x < N; ++x) {
    b[x] = x + 1;
  }
  for (int x = 0; x < M; ++x) {
    cin >> i >> j;
    temp = b[i - 1];
    b[i - 1] = b[j - 1];
    b[j - 1] = temp;
  }

  for (int x = 0; x < N; ++x) {
    cout << b[x] << " ";
  }
  return 0;
}