// https://www.acmicpc.net/problem/14729
#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<float> pq;
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    float temp;
    cin >> temp;
    pq.push(temp);
    if (pq.size() > 7) {
      pq.pop();
    }
  }
  stack<float> cmh;
  while(pq.size()) {
    cmh.push(pq.top()); pq.pop();
  }

  while(cmh.size()) {
    printf("%.3f\n", cmh.top()); cmh.pop();
  }

  return 0;
}