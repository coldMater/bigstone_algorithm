#include <bits/stdc++.h>
using namespace std;

int N, M;
string name;
map<string, bool> m;
vector<string> dbj;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> name;
    m[name] = true;
  }
  for (int i = 0; i < M; ++i) {
    cin >> name;
    if (m.find(name) != m.end()) dbj.push_back(name);
  }

  sort(dbj.begin(), dbj.end());
  cout << dbj.size() << "\n";
  for (string n : dbj) {
    cout << n << "\n";
  }
  return 0;
}