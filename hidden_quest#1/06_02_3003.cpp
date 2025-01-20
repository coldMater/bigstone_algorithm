#include <bits/stdc++.h>
using namespace std;

int o[6] = { 1, 1, 2, 2, 2, 8};
int t;
int main () {
  for (int i = 0; i < 6; ++i) {
    cin >> t;
    cout << o[i] - t << " ";
  }
  return 0;
}
