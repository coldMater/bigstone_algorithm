// https://www.acmicpc.net/problem/14405
#include <bits/stdc++.h>
using namespace std;

string o;
int c = 0; // cursor
bool r; // result

bool check(int cur, char tc) { // cursor, target character
  if (cur >= o.length()) return false;
  return o[cur] == tc;
}

int main () {
  cin >> o;
  while (true) {
    if (o.length() == c) {
      r = true;
    }
    if (o.length() <= c) break;
    if (check(c, 'p')) { // pi
      c++;
      if (check(c, 'i')) {
        c++;
        continue;
      }

      r = false;
      break;
    } 

    if (check(c, 'k')) { // ka
      c++;
      if (check(c, 'a')) {
        c++;
        continue;
      }

      r = false;
      break;
    }

    if (check(c, 'c')) { // chu
      c++;
      if (check(c, 'h')) {
        c++;
        if (check(c, 'u')) {
          c++;
          continue;
        }
      }

      r = false;
      break;
    }

    r = false;
    break;
  } 

  if (r) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}