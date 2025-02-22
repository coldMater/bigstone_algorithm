// https://www.acmicpc.net/problem/16235
#include <bits/stdc++.h>
using namespace std;

struct T { // tree
  int age;
  bool isDead;
};

int N, M, K;
int A[10][10];
vector<T> ts[10][10]; // trees
int ns[10][10]; // nutrients

int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void showTreeCount () {
  cout << "tree counts: \n";
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << ts[i][j].size() << " ";
    }
    cout << "\n";
  }
}

void showNutritionAmount () {
  cout << "nutrition counts: \n";
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << ns[i][j] << " ";
    }
    cout << "\n";
  }
}

void spring () {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = ts[i][j].size() - 1; k >= 0; --k) { // ⚠️ Caution: Traversal direction (starting from the youngest tree)
        if (ns[i][j] - ts[i][j][k].age < 0) {
          ts[i][j][k].isDead = true;
        } else {
          ns[i][j] -= ts[i][j][k].age;
          ts[i][j][k].age++;
        }
      }
    }
  }
}

void summer() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = ts[i][j].size() - 1; k >= 0; --k) {
        if (ts[i][j][k].isDead) {
          ns[i][j] += ts[i][j][k].age / 2; // ⚠️ Caution: From the problem statement (half of the age becomes nutrients)
          ts[i][j].erase(ts[i][j].begin() + k);
        }
      }
    }
  }
}

void fall() {
  int n[N][N];
  memset(n, 0, sizeof(n));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (T t : ts[i][j]) {
        if (t.age % 5 != 0) continue;
        for (int k = 0;  k < 8; ++k) {
          int ny = i + dy[k];
          int nx = j + dx[k];
          if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
          n[ny][nx]++;
        }
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < n[i][j]; ++k) {
        ts[i][j].push_back({ 1, false });
      }
    }
  }
}

void winter() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      ns[i][j] += A[i][j];
    }
  }
}

int main () {
  cin >> N >> M >> K;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> A[i][j];
      ns[i][j] = 5;
    }
  }

  for (int i = 0; i < M; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    ts[x - 1][y - 1].push_back({ z, false });
  }

  // showTreeCount();
  for (int i = 0; i < K; ++i) {
    // cout << "\nspring (k: " << i << ")\n";
    spring();
    // showTreeCount();
    // showNutritionAmount();
    // cout << "\nsummer (k: " << i << ")\n";
    summer();
    // showNutritionAmount();
    // cout << "\nfall (k: " << i << ")\n";
    fall();
    // showTreeCount();
    // cout << "\nwinter (k: " << i << ")\n";
    winter();
    // showTreeCount();
    // showNutritionAmount();
  }

  int sum = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      sum += ts[i][j].size();
    }
  }
  cout << sum;
  return 0;
}
