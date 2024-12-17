// https://www.acmicpc.net/problem/1561
#include <bits/stdc++.h>
using namespace std;

long long N;
int M;
int ts[10'000]; // time of each machine
int slot[10'000];
long long ans;
int main () {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> ts[i];
  }
  // cout << N;

  long long l = 1;
  long long r = 2'000'000'000LL * 30LL; // There is only one machine, and it takes 30 minutes.
  while (l <= r) {
    long long t = (l + r) / 2; // time

    long long cnt = 0;
    for (int i = 0 ; i < M; ++i) {
      long long cs = t / ts[i]; // During time t, the number of children who ride the i-th ride.
      if (t % ts[i] != 0) cs++; // Counting the number of children who can remain on that ride.
      cnt += cs;
    }

    // cout << "cnt: " << cnt << "\n";
    if (cnt >= N) {
      r = t - 1;
      ans = t;
    } else {
      l = t + 1;
    }

    // cout << "t: " << t << ", ans: " << ans << "\n";
  }

  // Simulate the last 1 second before.    
  int cnt = 0;
  long long t_1 = ans - 1;
  for (int i = 0; i < M; ++i) {
    long long c = t_1 / ts[i];
    slot[i] = t_1 % ts[i];
    if (slot[i] > 0) c++;
    cnt += c;
    // cout << slot[i] << " ";
  }
  // cout << "\n";

  for (int i = 0; i < M; ++i) {
    if (slot[i] == 0) {
      cnt++;
      if (cnt >= N) {
        cout << i + 1;
        break;
      }
    }
  }

  return 0;
}