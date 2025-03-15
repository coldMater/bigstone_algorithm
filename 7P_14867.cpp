// https://www.acmicpc.net/problem/14867
#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
map<int, map<int, int>> v;
char actionA[6] = {'F', 'F', 'E', 'E', 'M', 'M'};
char actionB[6] = {'a', 'b', 'a', 'b', 'a', 'b'};

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

  queue<pair<int, int>> q;
  q.push({0, 0});
  v[0][0] = 0;

  while (!q.empty()) {
    int pa, pb;
    tie(pa, pb) = q.front();q.pop();
    if (pa == c && pb == d) {
      cout << v[pa][pb];
      return 0;
    }
    for (int i = 0; i < 6; ++i) {
      int na, nb;
      tie(na, nb) = getNext(pa, pb, actionA[i], actionB[i]);

      if (v.find(na) != v.end() && v[na].find(nb) != v[na].end()) continue;
      q.push({na, nb});
      v[na][nb] = v[pa][pb] + 1;
    }
  }

  cout << -1;
  return 0;
}