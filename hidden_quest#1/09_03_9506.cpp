#include <bits/stdc++.h>
using namespace std;

int n;
int main () {
  // cin.tie(NULL);
  // cout.tie(NULL);
  // ios_base::sync_with_stdio(false);
  while (true) {
    cin >> n;
    if (n == -1) break;

    int sum = 0;
    vector<int> factors;
    for (int i = n - 1; i >= 1; --i) {
      if (n % i == 0) {
        factors.push_back(i);
        sum += i;
      }
    }
    cout << n;
    if (sum == n) {
      cout << " = ";
      while (factors.size()) {
        cout << factors.back();
        factors.pop_back();
        if (factors.empty()) cout << "\n";
        else cout << " + ";
      }
    } else {
      cout << " is NOT perfect.\n";
    }
  }
  return 0;
}
