// https://www.acmicpc.net/problem/2439
#include <bits/stdc++.h>
using namespace std;

int N;
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int sc = i + 1; // star count
    int bc = N - sc; // blank count
    for (int j = 0; j < bc; ++j) {
      cout << " ";
    }
    for (int j = 0; j < sc; ++j) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}