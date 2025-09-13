// https://www.acmicpc.net/problem/1280
#include <bits/stdc++.h>
using namespace std;

int N;
int X[200'000];
long long ft_cnt[200'002]; // fenwick-tree total count of trees
long long ft_sum[200'002]; // fenwick-tree sum of count of trees
int mx = 0;
void update (int i, int v, long long ft[]) {
  // cout << "update start!\n";
  while (i <= mx) {
    // cout << "i: " << i << "\n";
    ft[i] += v;
    i = i + (i & -i);
  }
}

long long query (int i, long long ft[]) {
  long long t = 0;
  while (i > 0) {
    t += ft[i];
    i = i - (i & -i);
  }
  return t;
}


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
    X[i]++; // ⚠️ A coordinate can be 0. Using 0 as a Fenwick tree index can lead to an infinite loop.
    mx = max(mx, X[i]);
  }

  // first tree
  update(X[0], 1, ft_cnt);
  update(X[0], X[0], ft_sum);

  long long answer = 1;
  for (int i = 1; i < N; ++i) {
    long long leftCnt = query(X[i], ft_cnt); // ⚠️ It is necessary to use long long instead of int.
    long long rightCnt = query(mx, ft_cnt) - query(X[i], ft_cnt); // ⚠️ It is necessary to use long long instead of int.
    long long leftSum = query(X[i], ft_sum);
    long long rightSum = query(mx, ft_sum) - query(X[i], ft_sum);
    long long leftE = leftCnt * X[i] - leftSum; // expense // ⚠️ If both leftCnt and X[i] are of type int, it could result in overflow.
    long long rightE = rightSum - rightCnt * X[i]; // expense // ⚠️ If both leftCnt and X[i] are of type int, it could result in overflow.

    // cout << "X[i]: " << X[i] << "\n";
    // cout << "leftCnt: " << leftCnt << ", leftSum: " << leftSum << ", leftE: " << leftE << "\n";
    // cout << "rightCnt: " << rightCnt << ", rightSum: " << rightSum << ", rightE: " << rightE << "\n";
    answer *= ((leftE + rightE) % 1'000'000'007); // ⚠️ Modular operation is required.
    answer %= 1'000'000'007;

    update(X[i], 1, ft_cnt);
    update(X[i], X[i], ft_sum);
    // cout << "cnt: ";
    // for (int j = 1; j <= 20; ++j) {
    //   cout << ft_cnt[j] << " ";
    // }
    // cout << "\n";
    // cout << "sum: ";
    // for (int j = 1; j <= 20; ++j) {
    //   cout << ft_sum[j] << " ";
    // }
    // cout << "\n";
  }

  cout << answer;
  return 0;
}