// https://www.acmicpc.net/problem/2343
#include <bits/stdc++.h>
using namespace std;

int N, M;
int lls[100'000]; // length of lectures;
int longest; // for the purpose of setting initial left border of binary search (situation for if a bluray has only one lecture)
int totalLength; // for the purpose of setting initial right border of binary search
int ans = 1'987'654'321;
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> lls[i];
    longest = max(longest, lls[i]); // at least one lecture should be contained in one bluray
    totalLength += lls[i];
  }

  int l = longest;
  int r = totalLength;
  while (l <= r) {
    int mid = (l + r) / 2; // mid: length of bluray

    int bluNum = 0; // count number of bluray
    int ts = 0; // temporary sum
    for (int i = 0; i < N; ++i) {
      ts += lls[i];
      if (ts > mid) {
        bluNum++;
        ts = lls[i];
      } else if(ts == mid) {
        bluNum++;
        ts = 0;
      }
    }
    if (ts > 0) bluNum++;
    // cout << "\n";
    // cout << "bluNum: " << bluNum << ", mid: " << mid << "\n";

    if (bluNum < M) {
      // lower length (reduce bluray length that included in one bluray)
      ans = min(ans, mid);
      r = mid - 1;
    } else if (bluNum > M) {
      // increase length (enhance bluray length that included in one bluray)
      l = mid + 1;
    } else { // nb == M 
      ans = min(ans, mid);
      // to find minimum
      r = mid - 1;
    }
  }

  cout << ans;
  return 0;
}