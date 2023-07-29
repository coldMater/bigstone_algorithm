// https://www.acmicpc.net/problem/2529
#include <bits/stdc++.h>
using namespace std;

int N;
char s[9]; // symbol
int ns[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // numbers
long long m = 99999999999; // min
int minSnapshot[10];
long long M = 0; // MAX
int MaxSnapshot[10];

void swap(int a, int b) {
  int temp = ns[a];
  ns[a] = ns[b];
  ns[b] = temp;
}

// void print () {
//   cout << "\n";
//   for (int num : ns) {
//     cout << num;
//   }
// }

bool it (char s, int a, int b) {
  if (s == '<') {
    return a < b;
  } else if (s == '>') {
    return a > b;
  }
  cout << "ASSERT: INVALID" << "\n";
  return false;
}

void p(int n, int r, int d) {
  if (d == r) {
    // cout << ns[0] << ns[1] << ns[2] << '\n';
    bool isAllTrue = true;
    for (int i = 0; i < r - 1; ++i) {
      isAllTrue = isAllTrue && it(s[i], ns[i], ns[i + 1]);
      if (!isAllTrue) break;
    }
    if (!isAllTrue) return;

    long long num = 0;
    for (int i = 0; i < r; ++i) {
      num += ns[i] * (long long)(pow(10, r - 1 - i));
    }

    if (m > num) {
      memcpy(minSnapshot, ns, sizeof(ns));
      m = num;
    }
    if (M < num) {
      memcpy(MaxSnapshot, ns, sizeof(ns));
      M = num;
    }

    return;
  }
  for (int i = d; i <= n; ++i) {
    swap(d, i);
    p(n, r, d + 1);
    swap(d, i);
  }
}

int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> s[i];
  }

  p(9, N + 1, 0);

  for (int i = 0; i < N + 1; ++i) {
    cout << MaxSnapshot[i];
  }
  cout << "\n";
  for (int i = 0; i < N + 1; ++i) {
    cout << minSnapshot[i];
  }

  return 0;
}