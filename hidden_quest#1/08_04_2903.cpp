#include <bits/stdc++.h>
using namespace std;

int N;
int main () {
  cin >> N;
  int l = (1 << N) + 1;
  cout << l * l;
  return 0;
}