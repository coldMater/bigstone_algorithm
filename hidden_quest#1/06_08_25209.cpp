#include <bits/stdc++.h>
using namespace std;

string s;
double point;
string grade;
double ac; // available count
double sum;
int main () {
  for (int i = 0; i < 20; ++i) {
    cin >> s;
    cin >> point;
    cin >> grade;
    if (grade == "P") continue;

    sum += point * (
      grade == "A+" ? 4.5
      : grade == "A0" ? 4.0
      : grade == "B+" ? 3.5
      : grade == "B0" ? 3.0
      : grade == "C+" ? 2.5
      : grade == "C0" ? 2.0
      : grade == "D+" ? 1.5
      : grade == "D0" ? 1.0
      : 0
    );

    ac += point;
  }
  // cout << sum << "\n";
  // cout << ac << "\n";
  cout << sum / ac;
  return 0;
}