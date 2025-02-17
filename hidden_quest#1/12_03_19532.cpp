#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f;
int main () {
  cin >> a >> b >> c >> d >> e >> f;
  cout << (e * c - b * f) / (a * e - b * d);
  cout << " ";
  cout << (-c * d + a * f) / (a * e - b * d);
  return 0;
}