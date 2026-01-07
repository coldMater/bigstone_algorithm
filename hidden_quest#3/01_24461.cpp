// https://www.acmicpc.net/problem/24416

#include <bits/stdc++.h>
using namespace std;

int n;
int res_recursively, res_dynamically;
int fib(int n) {
    if (n == 1 || n == 2) {
      res_recursively++;
      return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int f[41];
int fibonacci(int n) {
    f[0] = 1;
    f[1] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        res_dynamically++;
    }
    return f[n];
}

int main () {
  cin >> n;
  fib(n);
  fibonacci(n);
  cout << res_recursively << " " << res_dynamically;
  return 0;
}