// https://www.acmicpc.net/problem/17623
#include <bits/stdc++.h>
using namespace std;

int T, N;
string n[1001];

string compare (string a, string b) {
  if (a == "") return b;
  if (a.length() > b.length()) {
    return b;
  } else if (a.length() < b.length()) {
    return a;
  } else {
    return a < b ? a : b;
  }
}

int main () {
  cin >> T;
  for (int i = 0; i < T; ++i) {

    n[1] = "12"; // ()

    // n[2]
    // n[2] = n[1] + n[1];
    // n[2] = "1" + n[1] + "2"; // (x)
    n[2] = "34"; // {}

    // n[3]
    // n[3] = n[2] + n[1];
    // n[3] = n[1] + n[2];
    // n[3] = "3" + n[1] + "4"; // {x}
    n[3] = "56"; // []

    // n[4]
    // n[4] = n[3] + n[1]; // []()
    // n[4] = n[2] + n[2]; // {}{}
    n[4] = n[1] + n[3]; // ()[]
    // n[4] = "1" + n[2] + "2"; // ({})
    // n[4] = "5" + n[1] + "6"; // [()]

    cin >> N;
    for (int j = 5; j <= N; ++j) {
      if (n[j] != "") continue;
      for (int k = 1; k <= j - 1; ++k) {
        // cout << "j: " << j << ", " << k << "-" << j-k << "\n";
        n[j] = compare(n[j], n[k] + n[j - k]);
      }

      if (j % 2 == 0) {
        n[j] = compare(n[j], "1" + n[j / 2] + "2");
      }
      if (j % 3 == 0) {
        n[j] = compare(n[j], "3" + n[j / 3] + "4");
      }
      if (j % 5 == 0) {
        n[j] = compare(n[j], "5" + n[j / 5] + "6");
      }
    }

    // print
    for (char c : n[N]) {
      if (c == '1') cout << '(';
      if (c == '2') cout << ')';
      if (c == '3') cout << '{';
      if (c == '4') cout << '}';
      if (c == '5') cout << '[';
      if (c == '6') cout << ']';
    }
    cout << "\n";
  }
  return 0;
}