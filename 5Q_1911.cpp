// https://www.acmicpc.net/problem/1911
#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<pair<int, int>> p; // ponds
int main () {
  cin >> N >> L;
  for (int i = 0; i < N; ++i) {
    int start, end;
    cin >> start >> end;
    p.push_back({start, end});
  }

  // for (int i = 0; i < p.size(); ++i) {
  //   cout << p[i].first << "," << p[i].second << "\n";
  // }

  sort(p.begin(), p.end());
  // cout << "\n";

  // for (int i = 0; i < p.size(); ++i) {
  //   cout << p[i].first << "," << p[i].second << "\n";
  // }

  int count = 0;
  int right = 0;

  // int right = p[0].first;
  // cout << "put panel: " << "(count: " << count << ", " << right - N + 1 << "-" << right << ")\n";

  for (int i = 0; i < p.size(); ++i) {
    if (right < p[i].first) { // if the pond's left side is in panel applied right before
      right = p[i].first;
    }

    while (right < p[i].second) {
      right += L; // ⚠️ mistake
      count++;
      // cout << "put panel: " << "(count: " << count << ", " << right - N << "-" << right - 1 << ")\n";
    }
  }

  cout << count;

  return 0;
}
