// https://www.acmicpc.net/problem/10430
#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int main () {
  cin >> A >> B >> C;
  cout << (A+B)%C << "\n";
  cout << ((A%C) + (B%C))%C << "\n";
  cout << (A*B)%C << "\n";
  cout << ((A%C) * (B%C))%C << "\n";
  return 0;
}