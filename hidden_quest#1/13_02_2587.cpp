#include <bits/stdc++.h>
using namespace std;

int n[5];
int sum;
int main () {
  for (int i = 0; i < 5; ++i) {
    cin >> n[i];
    sum += n[i];
  }

  int mid = 0;
  sort(n, n + 5);
  cout << sum / 5 << "\n";
  cout << n[2];
}