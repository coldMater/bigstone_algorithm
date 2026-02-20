// https://www.acmicpc.net/problem/9251
#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
vector<char> A;
vector<char> B;
int main () {
  string t1;
  string t2;
  cin >> t1;
  cin >> t2;
  A.push_back(' '); B.push_back(' '); // spacer
  for (int i = 0; i < t1.length(); ++i) {
    A.push_back(t1.at(i));
    B.push_back(t2.at(i));
  }

  for (int i = 1; i <= t1.length(); ++i) {
    for (int j = 1; j <= t1.length(); ++j) {
      if (A[i] == B[j]) {
        arr[i][j] = arr[i - 1][j - 1] + 1;
      } else {
        arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
      }
    }
  }

  // { // debugging
  //   cout << "  ";
  //   for (int i = 0; i <= t1.length(); ++i) {
  //     cout << B[i] << " ";
  //   }
  //   cout << "\n";

  //   for (int i = 0; i <= t1.length(); ++i) {
  //     cout << A[i] << " ";
  //     for (int j = 0; j <= t1.length(); ++j) {
  //       cout << arr[i][j] << " ";
  //     }
  //     cout << "\n";
  //   }
  // }

  cout << arr[t1.length()][t1.length()];

  return 0;
}