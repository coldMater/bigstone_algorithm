#include <bits/stdc++.h>
using namespace std;

int N;
int main () {
  cin >> N;
  int a = 1;
  int sum = 1;
  while (true) {
    if (sum >= N) break;
    a++;
    sum += 6 * (a - 1);
  }
  cout << a;
  return 0;
}