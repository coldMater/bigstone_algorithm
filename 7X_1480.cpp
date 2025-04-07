// https://www.acmicpc.net/problem/1480
#include <bits/stdc++.h>
using namespace std;

int N; // number of jewels N (1 <= N <= 13)
int M; // number of bags M (1 <= M <= 10)
int C; // maximum capacity of each bag (1 < C <= 20)
int js[13]; // weight of jewels (each element: 1 <= weight <= 20)

int bags[10];
bool put (int n, int w) { // n: bag number, w: weight
  if (bags[n] + w > C) {
    return false; // can't put jewel in the bag 
  }

  bags[n] += w;
  return true;
}

void takeOut(int n, int w) {
  bags[n] -= w;
}

int go(int i) {
  if (i == N) {
    return 0;
  }

  // not
  int mx = 0;
  mx = max(go (i + 1), mx);
  
  // put jewels in the bag
  for (int j = 0; j < M; ++j) {
    if (put(j, js[i])) {
      mx = max(go (i + 1) + 1, mx);
      takeOut(j, js[i]);
    }
  }

  return mx;
}

int main () {
  cin >> N >> M >> C;

  for (int i = 0; i < N; ++i) {
    cin >> js[i];
  }

  cout << go (0);
  return 0;
}