// https://www.acmicpc.net/problem/9251
#include <bits/stdc++.h>
using namespace std;

int arr[1002][1002];
vector<char> A;
vector<char> B;
int main () {
  string t1;
  string t2;
  cin >> t1;
  cin >> t2;
  A.push_back(' '); B.push_back(' '); // padding for 1-based indexing
  for (int i = 0; i < t1.length(); ++i) {
    A.push_back(t1.at(i));
  }
  for (int i = 0; i < t2.length(); ++i) { // ⚠️ Lengths of A and B can be different
    B.push_back(t2.at(i));
  }

  for (int i = 1; i <= t1.length(); ++i) {
    for (int j = 1; j <= t2.length(); ++j) {
      if (A[i] == B[j]) {
        arr[i][j] = arr[i - 1][j - 1] + 1;
      } else {
        arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
      }
    }
  }

  // { // for debugging
  //   cout << "  ";
  //   for (int i = 0; i <= t1.length(); ++i) {
  //     cout << B[i] << " ";
  //   }
  //   cout << "\n";

  //   for (int i = 0; i <= t1.length(); ++i) {
  //     cout << A[i] << " ";
  //     for (int j = 0; j <= t2.length(); ++j) { // fixed: should use t2.length() for columns
  //       cout << arr[i][j] << " ";
  //     }
  //     cout << "\n";
  //   }
  // }

  cout << arr[t1.length()][t2.length()];

  return 0;
}