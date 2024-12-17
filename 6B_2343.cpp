// https://www.acmicpc.net/problem/2343
#include <bits/stdc++.h>
using namespace std;

int N, M;
int lls[100'000]; // lengths of lectures
int longest; // used to set the initial left boundary of binary search (minimum possible Blu-ray size when each Blu-ray contains only one lecture)
int totalLength; // used to set the initial right boundary of binary search (maximum possible Blu-ray size when all lectures are stored in a single Blu-ray)
int ans = 1'987'654'321;

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> lls[i];
    longest = max(longest, lls[i]); // at least one lecture must fit on a Blu-ray
    totalLength += lls[i];
  }

  int l = longest;
  int r = totalLength;
  while (l <= r) {
    int mid = (l + r) / 2; // mid: current candidate for Blu-ray size

    int bluNum = 0; // number of Blu-rays needed
    int ts = 0; // temporary sum to calculate Blu-ray content size
    for (int i = 0; i < N; ++i) {
      ts += lls[i];
      if (ts > mid) {
        bluNum++; // start a new Blu-ray
        ts = lls[i]; // current lecture starts the new Blu-ray
      } else if (ts == mid) {
        bluNum++; // perfectly fills a Blu-ray
        ts = 0; // reset temporary sum for the next Blu-ray
      }
    }
    if (ts > 0) bluNum++; // count any remaining lectures on the last Blu-ray

    if (bluNum < M) {
      // Fewer Blu-rays are needed than allowed; reduce Blu-ray size
      ans = mid;
      r = mid - 1;
    } else if (bluNum > M) {
      // More Blu-rays are needed than allowed; increase Blu-ray size
      l = mid + 1;
    } else { 
      // Exactly M Blu-rays are used; minimize Blu-ray size
      ans = mid;
      r = mid - 1;
    }
  }

  cout << ans;
  return 0;
}
