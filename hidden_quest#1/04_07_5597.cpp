// https://www.acmicpc.net/problem/5597 
#include <bits/stdc++.h>
using namespace std;

int n[31];
int temp;
int main () {
  for (int i = 1; i <= 28; ++i) {
    cin >> temp;
    n[temp] = 1;
  }

  for (int i = 1; i <= 30; ++i) {
    if (n[i] == 0) {
      cout << i << "\n";
    }
  }
  return 0;
}