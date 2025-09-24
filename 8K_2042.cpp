// https://www.acmicpc.net/problem/2042
#include <bits/stdc++.h>
using namespace std;

int N, M, K;
long long arr[1'000'001];
long long fenwick_tree[1'000'001];

void update (int i, long long v) { // ⚠️ pain point: int v(X) -> long long v 
  while (i <= 1'000'000) {
    fenwick_tree[i] += v;
    i += i & -i;
  }
}

long long query (int i) {
  long long sum = 0;
  while (i > 0) {
    sum += fenwick_tree[i];
    i -= i & -i;
  }
  return sum;
}

int main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> N >> M >> K;
  for (int i = 1; i < N + 1; ++i) {
    long long temp;
    cin >> temp;
    update(i, temp);
    arr[i] = temp;
  }

  for (int i = 0; i < M + K; ++i) {
    int a;
    cin >> a;
    if (a == 1) {
      int b;
      long long c;
      cin >> b;
      cin >> c;
      update(b, c - arr[b]);
      arr[b] = c;
    }
    if (a == 2) {
      int b, c;
      cin >> b;
      cin >> c;
      long long res = query(c) - query(b - 1);
      cout << res << "\n";
    }
  }
  return 0;
}