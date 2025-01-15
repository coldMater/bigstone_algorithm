// https://www.acmicpc.net/problem/10818
#include <bits/stdc++.h>
using namespace std;

int N, temp;
int mm = 987'654'321, MM = -987'654'321; // min, MAX
int main () {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> temp;
    mm = min(mm, temp);
    MM = max(MM, temp);
  }
  cout << mm << " " << MM;
  return 0;
}