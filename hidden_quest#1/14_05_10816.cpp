#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
int N, M, in;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> in;
    m[in] = m[in] + 1;
  }
  cin >> M;
  for (int i = 0; i < M; ++i) {
    cin >> in;
    cout << m[in] << " ";
  }
  return 0;
}