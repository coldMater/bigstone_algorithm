// https://www.acmicpc.net/problem/10871
#include <bits/stdc++.h>
using namespace std;

int N, X, temp;
int main () {
  cin >> N >> X;
  for (int i = 0; i < N; ++i) {
    cin >> temp;
    if (temp < X) {
      cout << temp << " ";
    }
  }
  return 0;
}