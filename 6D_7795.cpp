// https://www.acmicpc.net/problem/7795
#include <bits/stdc++.h>
using namespace std;

int TC;
int N, M;
int a[20'000];
int b[20'000];
int l, r, mid, t;
int ans;

void printArr () {
  cout << "arrA: ";
  for (int i = 0; i < N; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
}

void printArr2 () {
  cout << "arrB: ";
  for (int i = 0; i < M; ++i) {
    cout << b[i] << " ";
  }
  cout << "\n";
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> TC;
  for (int i = 0; i < TC; ++i) {
    cin >> N;
    cin >> M;
    for (int j = 0; j < N; ++j) {
      cin >> a[j];
    }
    for (int j = 0; j < M; ++j) {
      cin >> b[j];
    }
    sort(a, a + N);
    sort(b, b + M);
    // printArr();
    // printArr2();

    ans = 0;
    for (int j = 0; j < N; ++j) {
      l = 0;
      r = M - 1;
      t = 0;
      // cout << "l: " << l << ", r: " << r << "\n";
      while (l <= r) {
        mid = (l + r) / 2;

        if (b[mid] < a[j]) {
          // cout << "b[mid]: " << b[mid] << ", a[j]: " << a[j] << "\n";
          l = mid + 1;
          t = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      // cout << "t: " << t << "\n";
      ans += t;
    }
    cout << ans << "\n";
  }
  return 0;
}