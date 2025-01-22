#include <bits/stdc++.h>
using namespace std;

int N, B;
vector<int> res;
int main () {
  cin >> N >> B;
  int n = N;
  while (n > 0) {
    res.push_back(n % B);
    n = n / B;
    // cout << "n: " << n << "\n";
  }

  while (!res.empty()) {
    int temp = res.back();
    if (temp < 10) cout << temp;
    else cout << (char) (temp + 55);
    res.pop_back();
  }
  return 0;
}