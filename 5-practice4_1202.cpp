// https://www.acmicpc.net/problem/1202
#include <bits/stdc++.h>
using namespace std;

int N, K;
priority_queue<int> pq;
int ret;
vector<pair<int, int>> jewels;
int bagWeights[300'001];
int main () {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    int weight;
    int price;
    cin >> weight >> price;
    jewels.push_back({ weight, price });
  }
  for (int i = 0; i < K; ++i) {
    cin >> bagWeights[i];
  }

  sort(bagWeights, bagWeights + K);
  sort(jewels.begin(), jewels.end());
  int ji = 0; // jewel index
  for (int i = 0; i < K; i++) {
    int bagSize = bagWeights[i];
    while (ji < N && jewels[ji].first <= bagSize) {
      pq.push(jewels[ji++].second);
    }
    if (pq.size()) {
      ret += pq.top();
      pq.pop();
    }
  }
  // while (!pq.empty()) {
  //   tie(p, w) = pq.top(); pq.pop();
  //   for (int i = 0; i < K; ++i) {
  //     if (backWeights[i] >= w) {
  //       // cout << backWeights[i] << " <- price: " << p << "\n";
  //       ret += p;
  //       break;
  //     }
  //   }
  // }

  cout << ret;

  return 0;
}