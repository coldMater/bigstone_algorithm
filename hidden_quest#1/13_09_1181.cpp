#include <bits/stdc++.h>
using namespace std;

int N;
string temp;
vector<string> v;
set<string> s;

bool compareByLen(string a, string b) {
  if (a.length() != b.length()) return a.length() < b.length();

  for (int i = 0; i < a.length(); ++i) {
    if (a[i] == b[i]) continue;
    return a[i] < b[i];
  }
  return true;
}

int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> temp;
    s.insert(temp);
  }

  for (string i : s) {
    v.push_back(i);
  }

  sort(v.begin(), v.end(), compareByLen);

  for (string i : v) {
    cout << i << "\n";
  }
  return 0;
}