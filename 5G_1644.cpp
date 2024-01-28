// https://www.acmicpc.net/problem/1644
#include <bits/stdc++.h>
using namespace std;

int N, ret;
vector<int> primes;
int main () {
  cin >> N;
  // Ερατοσθένης's sieve
  int nums[N + 1];
  fill(nums, nums + N + 1, 0);
  // for (int i = 0; i <= N; ++i) {
  //   cout << nums[i];
  // }

  for (int i = 2; i * i <= N; ++i) {
    if (nums[i] == 1) continue;
    for (int j = i * i; j <= N; j += i) {
      nums[j] = 1;
    }
  }

  for (int i = 2; i <= N; ++i) {
    if (nums[i] == 0) {
      primes.push_back(i);
      // cout << i << "\n";
    }
  }

  int l = 0;
  int h = 0;
  int sum = 0;
  while (true) {
    // printf("l: %d(%d), h: %d(%d)\n", l, l < primes.size() ? primes[l] : -1, h, h < primes.size() ? primes[h] : -1);
    if (sum >= N) {
      sum -= primes[l++];
    } else if (h >= primes.size()) { 
      break; 
    } else if (sum < N) {
       sum += primes[h++];
    }
    // cout << "sum: " << sum << "\n";
    if (sum == N) { ret++; }
  }
  
  cout << ret;

  return 0;
}
