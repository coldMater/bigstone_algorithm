#include <bits/stdc++.h>
using namespace std;

int N;
int n[1000000];
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> n[i];
  }
  sort(n, n + N);
  for (int i = 0; i < N; ++i) {
    cout << n[i] << "\n";
  }
  return 0;
}