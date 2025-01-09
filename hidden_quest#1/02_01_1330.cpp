// https://www.acmicpc.net/problem/1330
#include <bits/stdc++.h>
using namespace std;

int A, B;
int main () {
  cin >> A >> B;
  if (A > B) {
    cout << ">";
  } else if (A < B) {
    cout << "<";
  } else {
    cout << "==";
  }
  return 0;
}