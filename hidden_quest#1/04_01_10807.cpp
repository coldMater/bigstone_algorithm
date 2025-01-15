// https://www.acmicpc.net/problem/10807
#include <bits/stdc++.h>
using namespace std;

int N;
int n[100];
int v;
int res;
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> n[i];
  }
  cin >> v;
  for (int i = 0; i < N; ++i) {
    if (v == n[i]) res++;
  }

  cout << res;
  
  return 0;
}