#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int dp[101][101][101];
int w (int a, int b, int c) {
  int &dpv = dp[a + 50][b + 50][c + 50];
  if (dpv != 0) return dpv;
  // cout << a << " " << b << " " << c << "\n";
  if (a <= 0 || b <= 0 || c <= 0) return dpv = 1; // ⚠️ I struggled for a long time because I forgot to write the code as `dpv =`.
  if (a > 20 || b > 20 || c > 20) return dpv = w(20, 20, 20); // ⚠️ I struggled for a long time because I forgot to write the code as `dpv =`.
  if (a < b && b < c) return dpv = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c); // ⚠️ I struggled for a long time because I forgot to write the code as `dpv =`.

  return dpv = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main () {
  while (true) {
    cin >> a >> b >> c;
    if (a == -1 && b == -1 && c == -1) break;
    int res = w(a, b, c);
    printf("w(%d, %d, %d) = %d\n", a, b, c, res);
  }

  return 0;
}