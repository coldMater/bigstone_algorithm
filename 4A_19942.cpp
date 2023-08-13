// https://www.acmicpc.net/problem/19942
#include <bits/stdc++.h>
using namespace std;

int N, mp, mf, ms, mv;
int m[16][5];
int mm = 987654321;
struct Food{
	int mp, mf, ms, mv, cost; 
}; 
Food food[16]; 

string combG = "";
int main () {
  cin >> N;
  cin >> mp >> mf >> ms >> mv;

  for (int i = 0; i < N; ++i) {
    cin >> m[i][0] >> m[i][1] >> m[i][2] >> m[i][3] >> m[i][4]; 
  }

  for (int i = 0; i < 1 << N; ++i) {
    // cout << i << '\n';
    int s[5] = {0, 0, 0, 0, 0};
    string comb = "";// combination 
    for (int j = 0; j < N; ++j) {
      if (i & (1 << j)) {
        for (int k = 0; k < 5; ++k) {
          s[k] += m[j][k];
        }
        comb += to_string(j + 1) + " ";
        // cout << comb << "\n";
      }
    }
    // cout << s[0] << " " << s[1] << " " << s[2] << " " << s[3] << " " << s[4] << '\n';
    if (s[0] >= mp && s[1] >= mf && s[2] >= ms && s[3] >= mv) {
      if (mm >= s[4]) {
        // cout << "Minimal:" << i << " : " << comb << "--" << s[4] << "\n";
        string prevCombG = combG;
        combG = comb;
        // cout << "combG:" << combG << " : prevCombG: " << prevCombG << "\n";

        if (prevCombG != "" && mm == s[4] && prevCombG < comb) {
          combG = prevCombG;
        }
        // cout << "final combG:" << combG << "\n";

        mm = s[4];
      }
    }
    // cout << '\n';
  }

  if (mm == 987654321) {
    cout << -1;
    return 0;
  }

  cout << mm << "\n";
  cout << combG;

  return 0;
}