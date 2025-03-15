// https://www.acmicpc.net/problem/14867
#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
int INF = 1'234'567'890;
int mn = INF;
map<int, map<int, int>> v;
char actionA[6] = {'F', 'F', 'E', 'E', 'M', 'M'};
char actionB[6] = {'a', 'b', 'a', 'b', 'a', 'b'};
void go (int na, int nb, int nd) { // now a, now b
  cout << "na, nb, nd: " << na << "," << nb << "," << nd << "\n";
  if (na == c && nb == d) {
    cout << "done d:" << nd << "\n";
    mn = min(mn, nd);
    return;
  }
  int mn;
  if (v[na][nb]) {
    cout << "visited" << "\n";
    return;
  }

  v[na][nb] = 1;
  // F(a)
  if (na != a) go(a, nb, nd + 1);

  // F(b)
  if (nb != b) go(na, b, nd + 1);

  // E(a)
  if (na != 0) go(0, nb, nd + 1);

  // E(b)
  if (nb != 0) go(na, 0, nd + 1);

  // M(a,b)
  int rb = b - nb;
  if (na <= rb) {
    if (na != 0) go(0, nb + na, nd + 1);
  } else {
    if (nb != b) go(na - rb, b, nd + 1);
  }

  // M(b,a)
  int ra = a - na;
  if (nb <= ra) {
    if (nb != 0) go(na + nb, 0, nd + 1);
  } else {
    if (na != a) go(a, nb - ra, nd + 1);
  }
}

pair<int, int> getNext(int pa, int pb, char action, char target) {
  if (action == 'F' && target == 'a') return {a, pb};
  if (action == 'F' && target == 'b') return {pa, b};
  if (action == 'E' && target == 'a') return {0, pb};
  if (action == 'E' && target == 'b') return {pa, 0};
  if (action == 'M' && target == 'a') {
    int rb = b - pb;
    if (pa <= rb) return {0, pb + pa};
    else return  {pa - rb, b};
  }
  if (action == 'M' && target == 'b') {
    int ra = a - pa;
    if (pb <= ra) return {pa + pb, 0};
    else return {a, pb - ra};
  }

  throw "Error";
}

int main () {
  cin >> a >> b >> c >> d;

  // go(0, 0, 0);

  v[0][0] = 0;
  queue<pair<int, int>> q;
  for (int i = 0; i < 6; ++i) {
    int na, nb;
    tie(na, nb) = getNext(0, 0, actionA[i], actionB[i]);
    if (na == 0 && nb == 0) continue;
    q.push({na, nb});
    v[na][nb] = 1;
  }
  while (!q.empty()) {
    int pa, pb;
    tie(pa, pb) = q.front();q.pop();
    for (int i = 0; i < 6; ++i) {
      int na, nb;
      tie(na, nb) = getNext(pa, pb, actionA[i], actionB[i]);
      if (na == pa && nb == pb) continue;
      // cout << na << ", " << nb << "\n";
      if (na == c && nb == d) {
        cout << v[pa][pb] + 1;
        return 0;
      }

      if (v.find(na) != v.end() && v[na].find(nb) != v[na].end()) continue;
      q.push({na, nb});
      v[na][nb] = v[pa][pb] + 1;
    }
  }

  cout << -1;
  return 0;
}