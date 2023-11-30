// https://www.acmicpc.net/problem/1062
#include <bits/stdc++.h>
using namespace std;

int N, K; // N: number of words, K: maximum number of characters that can be taught
string s;

// It doesn't necessarily have to be a string; a banana can be represented as 8195 in the following process.
// 'banana' -> 'b, a, n' -> ASCII codes: 98, 97, 110 -> 1, 0, 13 -> binary: 00000000 00000000 00100000 00000011 -> int: 8195
int wl[51];  // word list

void printMask (int mask) {
  for (char c = 'a'; c <= 'z'; ++c) {
    if (mask & (1 << (c - 'a'))) {
      cout << c;
    }
  }
  cout << '\n';
}

int jin(char alphabet, int depth, int mask) { // 進
  if (alphabet == 'z' + 1) {
    return 0; // through 'a' to 'z', can not make proper mask.
  }

  if (depth <= 0) {
    int count = 0;
    for (int i = 0; i < N; ++i) {
      // printMask(wl[i]);
      if ((wl[i] & mask) == wl[i]) count++;
    }
    // if (count) {
      // printMask(mask);
      // cout << count << "\n";
    // }
    // printMask(mask);

    return count;
  }

  int left = jin(alphabet + 1, depth - 1, mask | (1 << alphabet - 'a' + 1));
  // if (alphabet == 'a' || alphabet == 'n' || alphabet == 't' || alphabet == 'i' || alphabet == 'c') return left;
  int right = jin(alphabet + 1, depth, mask);
  return max(left, right);
}

int main () {
  cin >> N >> K;
  for (int l = 0; l < N; ++l) {
    cin >> s;
    for (char c : s) {
      int n = c - 'a';
      // cout << n << "\n";
      wl[l] |= (1 << n);
    }
  }
  // for (int i = 0; i < N; ++i) {
    // printMask(wl[i]);
    // printMask(mask);
  // }

  cout << jin ('a' - 1, K, 0);
  // printMask(10);

  return 0;
}
