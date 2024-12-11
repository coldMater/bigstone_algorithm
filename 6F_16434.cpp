// https://www.acmicpc.net/problem/16434
#include <bits/stdc++.h>
using namespace std;

struct room {
  bool rt; // room type (false: monster, true: potion)
  int a; // monster: atk, potion: increase atk
  int h; // monster: hp, potion: increase hp
};

int N;
int H_ATK;
long long ans = LLONG_MAX;
room rs[123'456]; // rooms
int main () {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL); cout.tie(NULL);

  cin >> N >> H_ATK;
  for (int i = 0; i < N; ++i) {
    int t, a, h;
    cin >> t >> a >> h;
    rs[i] = { t == 2, a, h };
  }

  // for (int i = 0; i < N; ++i) {
  //   printf("%d %d %d\n", rs[i].rt, rs[i].a, rs[i].h);
  // }

  long long l = 1;
  long long r = LLONG_MAX - 1;
  while (l <= r) {
    long long H_MaxHP = (l + r) / 2;
    long long H_CUR_ATK = H_ATK;
    // cout << "l: " << l << ", r: " << r << ", hp: " << H_MaxHP << "\n";

    bool lose = false;
    long long H_CurHP = H_MaxHP;
    for (int i = 0; i < N; ++i) {
      if (rs[i].rt) {
        // cout << "potion!\n";
        // potion
        H_CUR_ATK += rs[i].a;
        H_CurHP = min(H_MaxHP, H_CurHP + rs[i].h);
      } else {
        // cout << "monster!\n";
        // monster
        long long M_CurHP = rs[i].h;
        int M_ATK = rs[i].a;
        // printf("mhp: %d, matk: %d\n", M_CurHP, M_ATK);
        // cout << "H_ATK: " << H_CUR_ATK << "\n";

        long long atkCnt = (M_CurHP / H_CUR_ATK) + (M_CurHP % H_CUR_ATK ? 1 : 0);
        H_CurHP -= (atkCnt - 1) * M_ATK;
        if (H_CurHP <= 0) {
          break;
        }
        // while (true) {
        //   M_CurHP -= H_CUR_ATK;
        //   // cout << "mhp: " << M_CurHP << "\n";
        //   if (M_CurHP <= 0) break;
        //   H_CurHP -= M_ATK;
        //   // cout << "hhp: " << H_CurHP << "\n";
        //   if (H_CurHP <= 0) break;
        // }
      }
    }

    if (H_CurHP <= 0) {
      // lose
      l = H_MaxHP + 1;
      // cout << "lose!" << "next l: " << l << "\n\n";
    } else {
      // success
      ans = min(ans, H_MaxHP);
      r = H_MaxHP - 1;
      // cout << "win!" << "next r: " << r << "\n\n";
    }
  }
  cout << ans;
  return 0;
}