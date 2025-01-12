// https://www.acmicpc.net/problem/2739
#include<bits/stdc++.h>
using namespace std;

int N;
int main () {
  cin >> N;
  for (int i = 1; i <= 9; ++i) {
    cout << N << " * " << i << " = " << N * i << "\n";
  }
  return 0;
}