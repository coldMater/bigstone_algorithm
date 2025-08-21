// https://www.acmicpc.net/problem/1514
#include <bits/stdc++.h>
using namespace std;

int N;
int s[103]; // source state lock
int t[103]; // target state of lock
int dp[103][10][10][10];
int rotate (int res) {
  if (res < 0) return res + 10;
  else return res % 10;
}

int go(int i, int x, int y, int z) {
  if (i >= N) return 0;

  int &dpv = dp[i][x][y][z];
  if (dpv != -1) return dpv;
  
  dpv = 1e9;
  int optionA = t[i] - x; // targetting 1st disk to exact number
  int optionB = optionA > 0 ? -(10 - optionA) : 10 + optionA;
  int options[2] = { optionA, optionB };
  for (int dx : options) {
    for (int dy = 0; dy <= abs(dx); ++dy) { // 🚩 Each disk can be rotated up to the number of times the upper disk has been rotated. - https://dingcoding.tistory.com/377
      for (int dz = 0; dz <= dy; ++dz) {
        int d = dx < 0 ? -1 : 1; // direction
        int cnt = go(i + 1, rotate(y + dy * d), rotate(z + dz * d), s[i + 3]); 
        cnt += (abs(dx) - dy + 2) / 3 + (dy - dz + 2) / 3 + (dz + 2) / 3; // 🚩 Explain what this line means.
        dpv = min(dpv, cnt);
      }
    }
  }

  return dpv;
}

int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) scanf("%1d", &s[i]);
  for (int i = 0; i < N; ++i) scanf("%1d", &t[i]);
  memset(dp, -1, sizeof(dp));

  cout << go(0, s[0], s[1], s[2]);
  return 0;
}