#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, string> a[100'001];

bool compare (pair<int, string> a, pair<int, string> b) {
  return a.first < b.first;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> a[i].first >> a[i].second;
  }

  stable_sort(a, a + N, &compare); // 

  for (int i = 0; i < N; ++i) {
    cout << a[i].first << " " << a[i].second << "\n";
  }
}