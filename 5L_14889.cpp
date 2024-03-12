// https://www.acmicpc.net/problem/14889
#include <bits/stdc++.h>
using namespace std;

int N;
int S[20][20];

int res = 987654321;
vector<int> c;
void printVector () {
  for (int i = 0; i < c.size(); ++i) {
    cout << c[i] << " ";
  }
  cout << "\n";
}

void combi (int n, int r, int d) {
  if (c.size() == r) {
    int ml[N]; // member list
    // fill(l, l + N, 0);
    memset(ml, 0, sizeof(ml));
    for (int i : c) {
      ml[i] = 1;
    }
    vector<int> start;
    vector<int> link;
    for (int i = 0; i < N; ++i) {
      // cout << ml[i] << " ";
      if (ml[i]) start.push_back(i);
      else link.push_back(i);
    }

    int startTotal = 0;
    for (int m1 : start) {
      for (int m2 : start) {
        if (m1 == m2) continue;
        startTotal += S[m1][m2];
      }
    }

    int linkTotal = 0;
    for (int m1 : link) {
      for (int m2 : link) {
        if (m1 == m2) continue;
        linkTotal += S[m1][m2];
      }
    }

    res = min(abs(startTotal - linkTotal), res);
    // cout << "\n";
    // printVector();
    // cout << "startTotal: " << startTotal << "\n";
    // cout << "endTotal: " << linkTotal << "\n";
    // cout << "res: " << res << "\n";
    return;
  }

  for (int i = d; i < N; ++i) {
    c.push_back(i);
    combi (n, r, i + 1);
    c.pop_back();
  }
}

int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> S[i][j];
    }
  }

  combi(N, N / 2, 0);

  cout << res;
  return 0;
}