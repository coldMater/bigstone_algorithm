// https://www.acmicpc.net/problem/17612
#include <bits/stdc++.h>
using namespace std;

int N, k; // N: number of customer, k: number of register
int id, cnt;
struct C { // customer
  int id;
  int cnt;
  int register_num;
};

struct comp1 { // 💡 How to code priority_queue's comparator function.
  bool operator()(C& a, C& b) { // 💡 Meaning of the return value of the priority queue comparator: if true, a has higher priority.
    if (a.cnt == b.cnt) {
      return a.register_num > b.register_num;
    }
    return a.cnt > b.cnt;
  }
};

priority_queue<C, vector<C>, comp1> pq;

bool comp2 (C& a, C& b) {
  if (a.cnt == b.cnt) {
    return a.register_num > b.register_num; // ☠️ missing return statement
  }
  return a.cnt < b.cnt;
}

vector<C> v;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  cin >> N >> k;

  for (int i = 1; i <= k; ++ i) {
    cin >> id >> cnt;
    pq.push({ id, cnt, i });
  }

  for (int i = k + 1; i <= N; ++i) {
    cin >> id >> cnt;
    C outCustomer = pq.top(); pq.pop();
    pq.push({ id, outCustomer.cnt + cnt, outCustomer.register_num });
    v.push_back(outCustomer);
  }

  while (!pq.empty()) {
    v.push_back(pq.top());  pq.pop();
  }

  sort(v.begin(), v.end(), comp2);
  long long ans = 0;
  for (int i = 1; i <= N; ++i) {
    ans += (1LL * i) * v[i - 1].id;
  }
  cout << ans;
  return 0;
}