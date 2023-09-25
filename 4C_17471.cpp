// https://www.acmicpc.net/problem/17471
#include <bits/stdc++.h>
using namespace std;

int N;
int pl[11]; // population list
int m[11][11];
int v[11]; // visited
int a[11]; // area
const int A = 1;
const int B = 2;
int ret = 987654321;

void printMap () {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << m[i + 1][j + 1] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void print () {
  for (int i = 0; i < N; ++i) {
    cout << pl[i] << " ";
  }
  cout << "\n";
}

void printV () {
  for (int i = 0; i < N; ++i) {
    cout << v[i] << " ";
  }
  cout << "\n";
}

void printA () {
  for (int i = 0; i < N; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
}

void dfs (int s, int area) {
  // cout << s;
  if (v[s] == area) return;
  v[s] = area;

  for (int i = 0; i < N; ++i) {
    if (m[s + 1][i + 1] == 0 || a[i] != area) continue;
    // cout << "s: " << s << " i: " << i << "\n";
    // if (s == i) continue;
    if (v[i] == 0) {
      dfs(i, area);
    }
  }
}

int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> pl[i];
  }

  for (int i = 0; i < N; ++i) {
    int a = i + 1; // area number
    int c = 0; // count
    cin >> c;
    for (int i = 0; i < c; ++i) {
      int l = 0; // linked area
      cin >> l;
      m[a][l] = 1;
      m[l][a] = 1;
    }
  }

  // printMap();
  for (int i = 1; i < (1 << N) - 1; i++) {
    // area A
    int firstA = -1;
    int firstB = -1;
    for (int j = 0; j < N; ++j) {
      if ((1 << j) & i) {
        if (firstA == -1) firstA = j;
        a[j] = A;
      } else {
        if (firstB == -1) firstB = j;
        a[j] = B;
      }
    }
    dfs(firstA, A);
    dfs(firstB, B);

    int pA = 0;
    int pB = 0;
    int broken = false;
    for (int j = 0; j < N; ++j) {
      if (v[j] == 0) {
        broken = true;
        break; // Impossible Method as given in the problem
      }
      int area = a[j];
      int population = pl[j];
      if (area == A) {
        pA += pl[j];
      }
      if (area == B) {
        pB += pl[j];
      }
    }
    // cout << pA << " " << pB << "\n";

    if (!broken) {
      ret = min(ret, abs(pA - pB));
    }

    // printV();
    // printA();
    // printV();
    // cout << i << "\n";
    fill(v, v + 11, 0);
    // cout << "\n";
  }
  if (ret == 987654321) {
    cout << -1;
  } else {
    cout << ret;
  }

  return 0;
}