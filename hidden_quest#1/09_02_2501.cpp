#include <bits/stdc++.h>
using namespace std;

vector<int> n;
int N, K;
int main () {
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) {
    if (N % i == 0) n.push_back(i);
  }
  if (K - 1 >= n.size()) cout << 0;
  else cout << n[K - 1];
  return 0;
}