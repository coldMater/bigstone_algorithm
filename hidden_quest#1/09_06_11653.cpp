#include <bits/stdc++.h>
using namespace std;

int N;
int e = 1;
bool che[10'000'001];
int main () {
  cin >> N;
  if (N == 1) return 0;
  for (int p = 2; p <= N; ++p) {
    if (che[p] == true) continue;
    for (int i = p; i <= N; i += i) {
      che[p] = true;
    }

    while (N % p == 0) {
      cout << p << "\n";
      e *= p;
      N /= p;
    }
  }
  return 0;
}


// NOTE
// 1. first try: timeout (finding prime number)
// 2. second try: use `Sieve of Eratosthenes`