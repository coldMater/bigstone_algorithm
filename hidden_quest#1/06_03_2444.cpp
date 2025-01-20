#include <bits/stdc++.h>
using namespace std;

int N;
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N - i - 1; ++j) {
      cout << " ";
    }
    for (int j = 0; j < i + 1; ++j) {
      cout << "*";
    }
    for (int j = 0; j < i; ++j) {
      cout << "*";
    }
    cout << "\n";
  }
  for (int i = N - 2; i >= 0; --i) {
    for (int j = 0; j < N - i - 1; ++j) {
      cout << " ";
    }
    for (int j = 0; j < i + 1; ++j) {
      cout << "*";
    }
    for (int j = 0; j < i; ++j) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}