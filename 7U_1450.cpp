// https://www.acmicpc.net/problem/1450
#include <bits/stdc++.h>
using namespace std;

int N, C, in;
vector<int> items;

vector<int> totalsA;
vector<int> totalsB;

long long res;
void combine(int w, int i, int e, vector<int>& t) { // w: weight, i: index, e: end, t: target
  if (w > C) return;
  if (i == e) {
    if (w <= C) t.push_back(w);
    return;
  }

  combine(w + items[i], i + 1, e, t);
  combine(w, i + 1, e, t);
}

int main () {
  cin >> N >> C;
  for (int i = 0; i < N; ++i) {
    cin >> in;
    items.push_back(in);
  }

  combine(0, 0, N / 2, totalsA);
  combine(0, N / 2, N, totalsB);

  // for (int i = 0; i < totalsA.size(); ++i) {
  //   cout << totalsA[i] << " ";
  // }

  // cout << "\n";
  // for (int i = 0; i < totalsB.size(); ++i) {
  //   cout << totalsB[i] << " ";
  // }
  // cout << "\n";

  sort(totalsB.begin(), totalsB.end());
  for (int wA : totalsA) {
    res += upper_bound(totalsB.begin(), totalsB.end(), C - wA) - totalsB.begin();
  }

  cout << res;
  return 0;
}

// int main () {
//   int a[4] = { 1, 1, 2 };
//   cout << lower_bound(a, a + 3, -3) - a;
//   cout << "\n";
//   cout << upper_bound(a, a + 3, -3) - a;
// }