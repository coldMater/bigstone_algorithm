#include <bits/stdc++.h>
using namespace std;

int N, M, in;
map<int, bool> m;
int main () {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> in;
    m.insert({ in, true });
  }
  cin >>  M;
  for (int i = 0; i < M; ++i) {
    cin >> in;
    cout << (m.find(in) == m.end() ? 0 : 1) << " ";
  }
  return 0;
}