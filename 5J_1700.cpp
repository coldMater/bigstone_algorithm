// https://www.acmicpc.net/problem/1700
#include <bits/stdc++.h>
using namespace std;

int N, K, ret;
int gs[101]; // gadgets
  vector<int> mt; // multitap
int main () {
  cin >> N >> K ;
  for (int i = 0; i < K; ++i) {
    cin >> gs[i];
  }

  for (int i = 0; i < K; ++i) {
    // cout << "turn: " << i << "(gadget: " << gs[i] << ")" << "\n";
    if (mt.size() < N) {
      // cout << "empty slot available: " << gs[i] << "(" << i << ")\n\n";
      mt.push_back(gs[i]);
      continue;
    }

    // If the next gadget (gs[i]) is already plugged into the multitap, no action needs to be taken.
    bool is_already_plugged = false;
    for (int j = 0; j < mt.size(); ++j) {
      if (mt[j] == gs[i]) {
        // cout << gs[i] << "(" << i << ") already plugged\n\n";
        is_already_plugged = true;
        break;
      }
    }
    if (is_already_plugged) continue;

    int furthest_away = 0; 
    int to_be_replaced_mt_idx = 0;
    for (int j = 0; j < mt.size(); ++j) {
      int already_plugged = mt[j];
      // cout << "j: " << j << "(ap: " << already_plugged << ")\n";
      for (int r = i; r < K; ++r) { // r: remained(not plugged in yet)
        if (already_plugged == gs[r]) { // already plugged gadget is in the remained gadget list
          if (furthest_away < r) {
            furthest_away = r;
            to_be_replaced_mt_idx = j;
            // cout << "  : furthest gadget until now: " << gs[r] << "(r: " << r << ")\n";
          }
        } else {
            // cout << "  : - \n";
        }
      }
    }

    // cout << "end loop replacement target: " << gs[furthest_away] << " (idx: " << to_be_replaced_mt_idx << ")\n\n";
    ret++;
    mt.erase(mt.begin() + to_be_replaced_mt_idx);
  } 

  cout << ret;
  return 0;
}
