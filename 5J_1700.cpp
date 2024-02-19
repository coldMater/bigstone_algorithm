// https://www.acmicpc.net/problem/1700
#include <bits/stdc++.h>
using namespace std;

int N, K, ret;
int gs[101]; // gadgets
void printMt(vector<int> mt) {
  cout << "multitap: ";
  for (int i = 0; i < mt.size(); ++i) {
    cout << mt[i] << " ";
  }
  cout << "\n\n";
}

/**
 * check gadget exists in
 * @return index of gadget plugged in
*/
int check(int gadget, vector<int> mt) {
  for (int i = 0; i < N; ++i) {
    if (mt[i] == gadget) return i;
  }
  return -1;
}

/**
 * @return index of empty slot of multitap
*/
int empty(vector<int> mt) {
  for (int i = 0; i < N; ++i) {
    if (mt[i] == 0) return i;
  }
  return -1;
}

int main () {
  cin >> N >> K ;
  vector<int> mt(N); // multitap
  for (int i = 0; i < K; ++i) {
    cin >> gs[i];
  }

  for (int i = 0; i < K; ++i) {
    if (check(gs[i], mt) != -1) {
      // HIT: check whether gadget is already plugged in
      continue;
    }

    // MISS: the gadget(gs[i]) is not plugged in multitap.
    int emptyIdx = empty(mt);
    if (emptyIdx != -1) {
      // multitap empty slot available
      mt[emptyIdx] = gs[i];
      continue;
    }

    int maxDistance = 0;
    int multitapIdxToBeReplaced = 0;
    for (int j = 0; j < N; ++j) {
      int distance = 0;
      for (int r = i + 1; r < K; ++r) {
        // ⚠️ Be cautious when calculating the distance with the element at the last index of the array.
        // incorrect approach:
        // distance++;
        // if (gs[r] == mt[j]) break;
        if (gs[r] == mt[j]) break;
        distance++;
      }
      // cout << "plugged gadget: " << mt[j] << ", distance: " << distance << "\n";
      if (maxDistance < distance) {
        maxDistance = distance;
        multitapIdxToBeReplaced = j;
      }
    }
    // cout << "multitapIdxToBeReplaced: " << multitapIdxToBeReplaced << " , gadget: " << mt[multitapIdxToBeReplaced] << ", with: " << gs[i] << "\n";
    ret++;
    mt[multitapIdxToBeReplaced] = gs[i];
    // printMt(mt);
  }

  cout << ret;

  return 0;
}
