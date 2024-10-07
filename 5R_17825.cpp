// https://www.acmicpc.net/problem/17825
#include <bits/stdc++.h>
using namespace std;

               //   0                  5                  10                  15                  20                  25                  30  31  32
int scores[33] = {  0,  2,  4,  6,  8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 35, 30, 25, 24, 22, 13, 16, 19, 26, 27, 28, 0 };
int red[33] =    {  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13 ,14, 15, 16, 17, 18 ,19, 20, 32, 20, 21, 22, 23, 24, 27, 28, 23, 23, 29, 30, 0 };
int blue[33] =   {  0,  0,  0,  0,  0, 26,  0,  0,  0,  0, 25,  0,  0 , 0,  0, 31,  0,  0 , 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0 };

int dice[10];

int m;
vector<int> o; // order
void move(int d) { // depth, score
  if (d >= 10) {
    int malPos[4] = { 0, 0, 0, 0 }; // mal position
    int s = 0;
    // string log = "";
    for (int i = 0; i < 10; ++i) {
      int mn = o[i]; // mal number
      if (malPos[mn] == 32) continue;
      if (blue[malPos[mn]]) {
        malPos[mn] = blue[malPos[mn]];
      } else {
        malPos[mn] = red[malPos[mn]];
      }

      if (malPos[mn] == 32) continue;
      for(int m = 0; m < dice[i] - 1; m++) {
        if (malPos[mn] == 32) continue;
        malPos[mn] = red[malPos[mn]];
        if (malPos[mn] == 32) continue;
      }

      bool isOccupied = false;
      for (int j = 0; j < 4; ++j) {
        if (j == mn) continue;
        if (malPos[j] == malPos[mn]) isOccupied = true;
      }
      if (isOccupied && malPos[mn] < 32) break;

      s += scores[malPos[mn]];
      // log += to_string(scores[malPos[mn]]) + " + ";
    }
    // int b = m;
    m = max(m, s);
    // int a = m;
    // if (b != a) {
    //   cout << "max crashed! - " << m << "\n";
    //   cout << log << "\n";
    //   for (int e : o) {
    //     cout << e << " ";
    //   }
    //   cout << "\n";
    // }
    return;
  }

  for (int i = 0; i < 4; ++i) {
    o.push_back(i);
    move(d + 1);
    o.pop_back();
  }
}

int main () {
  // Node nodes[33];
  for (int i = 0; i < 10; i++) {
    cin >> dice[i];
  }

  move(0);

  cout << m;

  return 0;
}