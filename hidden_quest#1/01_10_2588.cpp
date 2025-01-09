// https://www.acmicpc.net/problem/2588
#include <bits/stdc++.h>
using namespace std;

int first, second;
int main () {
  cin >> first >> second;

  cout << first * (second % 10) << "\n";
  cout << first * ((second % 100) / 10) << "\n";
  cout << first * (second / 100) << "\n";
  cout << first * second << "\n";
  return 0;
}