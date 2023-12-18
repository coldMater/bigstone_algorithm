// https://www.acmicpc.net/problem/5430
#include <bits/stdc++.h>
using namespace std;

int T; // number of tests
int N; // number of elements
string strArr; // array string
int resultArr; // result array
string funcStr;
deque<int> arr;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> funcStr;
    cin >> N;
    cin >> strArr;

    string token = "";
    for (char e : strArr) {
      if (e == '[') continue;
      if (e == ',' || e == ']') {
        if (token != "") arr.push_back(stoi(token));
        token = "";
        continue;
      }
      token += e;
    }

    bool reversed = false;
    bool hasError = false;
    int left = 0;
    int right = arr.size() - 1;

    for (char c : funcStr) {
      if (c == 'R') {
        reversed = !reversed;
      } else if (c == 'D') {
        if (arr.empty()) {
          hasError = true;
          break;
        }
        if (reversed) {
          // cout << "removed back " << arr.back() << "\n";
          arr.pop_back();
        } else {
          // cout << "removed front " << arr.front() << "\n";
          arr.pop_front();
        }
      }
    }
    if (hasError) {
      cout << "error\n";
      continue;
    }

    cout << "[";
    if (reversed) {
      while (!arr.empty()) {
        cout << arr.back();
        arr.pop_back();
        if (!arr.empty()) cout << ",";
      }
    } else {
      while (!arr.empty()) {
        cout << arr.front();
        arr.pop_front();
        if (!arr.empty()) cout << ",";
      }
    }
    cout << "]\n";

    reversed = false;
    arr.clear();
  }
  return 0;
}