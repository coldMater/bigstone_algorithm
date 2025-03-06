#include <bits/stdc++.h>
using namespace std;

int N, n, i;

bool compare (pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  return a.second.first < b.second.first;
}

bool compareForTurnback(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  return a.first < b.first;
}

pair<int, pair<int, int>> nl[1'000'000]; // { idx, { num, cnt } }
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> n;
    nl[i] = { i, { n, 0 } };
  }

  sort(nl, nl + N, compare);

  int b = nl[0].second.first;
  for (int i = 1; i < N; ++i) {
    nl[i].second.second = nl[i - 1].second.second + !(nl[i].second.first == nl[i - 1].second.first);
    // if (nl[i].second.first == nl[i - 1].second.first) {
    //   nl[i].second.second = nl[i - 1].second.second;
    // } else {
    //   nl[i].second.second = nl[i - 1].second.second + 1;
    // }
  }

  sort(nl, nl + N, compareForTurnback);

  for (int i = 0; i < N; ++i) {
    cout << nl[i].second.second << " ";
  }

  return 0;
}