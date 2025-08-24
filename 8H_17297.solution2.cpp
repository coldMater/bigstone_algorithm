// https://www.acmicpc.net/problem/17297
#include <bits/stdc++.h>
using namespace std;

int l[50];
string a = "Messi "; // 5 + 1 = 6
string b = "Messi Gimossi "; // 13 + 1 = 14
int last = 2;
char find(int M, int i) {
  if (M <= 14) {
    return b[M - 1];
  }

  int val_n_1 = l[i - 1];

  int diff = M - val_n_1;
  if (diff > 0) return find(diff, i - 2);
  else return find(M, i - 1);
}

int M;
int main () {

  l[0] = 6; // "Messi" + " "
  l[1] = 14; // "Messi Gimossi" + " "
  for (int i = 2; i <= 40; ++i) {
    l[i] = l[i - 1] + l[i - 2];
    last = i;
  }

  cin >> M;
  int idx = lower_bound(l + 1, l + last, M) - l;
  char res = find(M, idx);
  if (res == ' ') {
    cout << "Messi Messi Gimossi";
  } else {
    cout << res;
  }

  return 0;
}