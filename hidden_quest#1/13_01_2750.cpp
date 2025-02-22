#include <bits/stdc++.h>
using namespace std;

int N;
int n[1000];
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> n[i];
  }

  for(int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (n[j] < n[i]) {
        int temp = n[j];
        n[j] = n[i];
        n[i] = temp;
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    cout << n[i] << "\n";
  }
  return 0;
}
