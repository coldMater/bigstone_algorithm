#include <bits/stdc++.h>
using namespace std;

int N;
string name, enterOrLeave;
map<string, bool, std::greater<string>> m;
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> name >> enterOrLeave;
    if (enterOrLeave == "enter") {
      m[name] = true;
    } else {
      m.erase(name);
    }
  }

  for (auto e : m) {
    cout << e.first << "\n";
  }
  return 0;
}