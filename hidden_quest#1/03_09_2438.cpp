// https://www.acmicpc.net/problem/2438
#include <bits/stdc++.h>
using namespace std;

int N;
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < i + 1; ++j) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}