// https://www.acmicpc.net/problem/2109
#include <bits/stdc++.h>
using namespace std;

int n;
int p[100'001];
int md;
int main () {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int price;
    int day;
    cin >> price >> day;
    if (p[day] < price) {
      p[day] = price;
      md = max(md, day);
    }
  }

  int sum = 0;
  for (int i = 1; i <= md; ++i) {
    // cout << "i: " << i << ", sum: " << sum << ", p: " << p[i] << "\n";
    sum += p[i];
  }

  cout << sum;

  return 0;
}
