#include <bits/stdc++.h>
using namespace std;

int N, in;
vector<int> n;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> in;
    n.push_back(in);
  }
  sort(n.begin(), n.end());
  for (int i = 0; i < N; ++i) {
    cout << n[i] << "\n";
  }
  return 0;
}