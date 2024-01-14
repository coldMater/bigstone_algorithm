// https://www.acmicpc.net/problem/1202
#include <bits/stdc++.h>
using namespace std;

int N, K;
priority_queue<int> pq;
long long ret; // The price of a jewel can be up to one hundred million, and the number of jewels is 300,000. This implies that the total price of jewels can exceed the upper limit of an integer data type.
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

  cout << ret;

  return 0;
}
