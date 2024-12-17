// https://www.acmicpc.net/problem/1561
#include <bits/stdc++.h>
using namespace std;

int N, M;
int ts[10'000]; // time of each machine
int slot[10'000];

void printSlot() {
  for (int i = 0; i < M; ++i) {
    cout << slot[i] << " ";
  }
  cout << "\n";
}

int main () {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> ts[i];
  }

  int cnt = N;
  while (true) {
    // phase1. boarding
    int ans = -1;
    for (int i = 0; i < M; ++i) {
      if (slot[i] == 0) { 
        slot[i] = ts[i];
        if (--cnt <= 0) {
          cout << i + 1;
          return 0;
        }
      };
    }
    // cout << "boarding: \n";
    // printSlot();

    // phase 2. tick
    for (int i = 0; i < M; ++i) {
      if (slot[i] > 0) slot[i]--;
    }
    // cout << "tick: \n";
    // printSlot();
    // cout << "\n";
  }

  return 0;
}