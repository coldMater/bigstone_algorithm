#include <bits/stdc++.h>
using namespace std;

int N, in;
map<int, int> m;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> in;
    m.insert({ in, in });
  }
  for (pair<int, int> o : m) {
    cout << o.second << "\n";
  }
  return 0;
}