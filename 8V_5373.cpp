// https://www.acmicpc.net/problem/5373
#include <bits/stdc++.h>
using namespace std;


struct Side {
  char b[3][3];
  Side* n; // north
  Side* e; // east
  Side* s; // south
  Side* w; // west
};

// void printSide(Side& S) {
//   for (int i = 0; i < 3; ++i) {
//     for (int j = 0; j < 3; ++j) {
//       cout << S.b[i][j] << " ";
//     }
//     cout << "\n";
//   }
//   cout << "\n";
// }

void init (Side& S, char color) {
  for(int i = 0; i < 3; ++i){
    for (int j = 0; j <3; ++j) {
      S.b[i][j] = color;
      // S.b[i][j] = 'a' + i * 3 + j;
    }
  }
}

void rotateSideClock(Side& S) {
  char temp; 

  // . 1 .      . 4 .
  // 4 0 2  ->  3 0 1
  // . 3 .      . 2 .
  temp = S.b[0][1];
  S.b[0][1] = S.b[1][0];
  S.b[1][0] = S.b[2][1];
  S.b[2][1] = S.b[1][2];
  S.b[1][2] = temp;

  // 8 . 5      7 . 8
  // . 0 .  ->  . 0 .
  // 7 . 6      6 . 5
  temp = S.b[0][0];
  S.b[0][0] = S.b[2][0];
  S.b[2][0] = S.b[2][2];
  S.b[2][2] = S.b[0][2];
  S.b[0][2] = temp;
}

void rotateSideAntiClock(Side& S) {
  char temp; 

  // . 4 .       . 1 .
  // 3 0 1  ->   4 0 2
  // . 2 .       . 3 .
  temp = S.b[0][1];
  S.b[0][1] = S.b[1][2];
  S.b[1][2] = S.b[2][1];
  S.b[2][1] = S.b[1][0];
  S.b[1][0] = temp;

  // 7 . 8      8 . 5
  // . 0 .  ->  . 0 .
  // 6 . 5      7 . 6
  temp = S.b[0][0];
  S.b[0][0] = S.b[0][2];
  S.b[0][2] = S.b[2][2];
  S.b[2][2] = S.b[2][0];
  S.b[2][0] = temp;
}

// void test (char& n) {
//   n = 'k';
//   cout << "test: " << n << "\n";
//   // cout << n[0] << n[1] << n[2];
// }

void rotateAround(char* n[3], char* e[3], char* s[3], char* w[3]) {  // ⚠️ `char* n` as a parameter type VS `char& n` as a parameter type
  char temp[3];
  temp[0] = *n[0]; temp[1] = *n[1]; temp[2] = *n[2];
  *n[0] = *w[0]; *n[1] = *w[1]; *n[2] = *w[2]; 
  *w[0] = *s[0]; *w[1] = *s[1]; *w[2] = *s[2]; 
  *s[0] = *e[0]; *s[1] = *e[1]; *s[2] = *e[2]; 
  *e[0] = temp[0]; *e[1] = temp[1]; *e[2] = temp[2]; 
}

void rotateAroundAnti(char* n[3], char* e[3], char* s[3], char* w[3]) {
  char temp[3];
  temp[0] = *n[0]; temp[1] = *n[1]; temp[2] = *n[2];
  *n[0] = *e[0]; *n[1] = *e[1]; *n[2] = *e[2]; 
  *e[0] = *s[0]; *e[1] = *s[1]; *e[2] = *s[2]; 
  *s[0] = *w[0]; *s[1] = *w[1]; *s[2] = *w[2]; 
  *w[0] = temp[0]; *w[1] = temp[1]; *w[2] = temp[2]; 
}

Side U; Side D; Side B; Side F; Side L; Side R;

// map<char, Side> m = { 
//   { 'U', U },
//   { 'D', D },
//   { 'B', B },
//   { 'F', F },
//   { 'L', L },
//   { 'R', R },
// };

void rotate_U(bool clockwise) {
  char* n[3] = { &B.b[0][2], &B.b[0][1], &B.b[0][0] };
  char* e[3] = { &R.b[0][2], &R.b[0][1], &R.b[0][0] };
  char* s[3] = { &F.b[0][2], &F.b[0][1], &F.b[0][0] };
  char* w[3] = { &L.b[0][2], &L.b[0][1], &L.b[0][0] };

  if (clockwise) {
    rotateSideClock(U);
    rotateAround(n, e, s, w);
  } else {
    rotateSideAntiClock(U);
    rotateAroundAnti(n, e, s, w);
  }
}

void rotate_B(bool clockwise) {
  char* n[3] = { &U.b[0][2], &U.b[0][1], &U.b[0][0] };
  char* e[3] = { &L.b[0][0], &L.b[1][0], &L.b[2][0] };
  char* s[3] = { &D.b[0][2], &D.b[0][1], &D.b[0][0] };
  char* w[3] = { &R.b[2][2], &R.b[1][2], &R.b[0][2] };

  if (clockwise) {
    rotateSideClock(B);
    rotateAround(n, e, s, w);
  } else {
    rotateSideAntiClock(B);
    rotateAroundAnti(n, e, s, w);
  }
}

void rotate_D(bool clockwise) {
  char* n[3] = { &B.b[2][0], &B.b[2][1], &B.b[2][2] };
  char* e[3] = { &L.b[2][0], &L.b[2][1], &L.b[2][2] };
  char* s[3] = { &F.b[2][0], &F.b[2][1], &F.b[2][2] };
  char* w[3] = { &R.b[2][0], &R.b[2][1], &R.b[2][2] };

  if (clockwise) {
    rotateSideClock(D);
    rotateAround(n, e, s, w);
  } else {
    rotateSideAntiClock(D);
    rotateAroundAnti(n, e, s, w);
  }
}

void rotate_F(bool clockwise) {
  char* n[3] = { &U.b[2][0], &U.b[2][1], &U.b[2][2] };
  char* e[3] = { &R.b[0][0], &R.b[1][0], &R.b[2][0] };
  char* s[3] = { &D.b[2][0], &D.b[2][1], &D.b[2][2] };
  char* w[3] = { &L.b[2][2], &L.b[1][2], &L.b[0][2] };

  if (clockwise) {
    rotateSideClock(F);
    rotateAround(n, e, s, w);
  } else {
    rotateSideAntiClock(F);
    rotateAroundAnti(n, e, s, w);
  }
}

void rotate_L(bool clockwise) {
  char* n[3] = { &U.b[0][0], &U.b[1][0], &U.b[2][0] };
  char* e[3] = { &F.b[0][0], &F.b[1][0], &F.b[2][0] };
  char* s[3] = { &D.b[2][2], &D.b[1][2], &D.b[0][2] };
  char* w[3] = { &B.b[2][2], &B.b[1][2], &B.b[0][2] };

  if (clockwise) {
    rotateSideClock(L);
    rotateAround(n, e, s, w);
  } else {
    rotateSideAntiClock(L);
    rotateAroundAnti(n, e, s, w);
  }
}

void rotate_R(bool clockwise) {
  char* n[3] = { &U.b[2][2], &U.b[1][2], &U.b[0][2] };
  char* e[3] = { &B.b[0][0], &B.b[1][0], &B.b[2][0] };
  char* s[3] = { &D.b[0][0], &D.b[1][0], &D.b[2][0] };
  char* w[3] = { &F.b[2][2], &F.b[1][2], &F.b[0][2] };

  if (clockwise) {
    rotateSideClock(R);
    rotateAround(n, e, s, w);
  } else {
    rotateSideAntiClock(R);
    rotateAroundAnti(n, e, s, w);
  }
}

int n;
int main () {
  cin >> n;
  while (n--) {
    init(U, 'w');
    init(D, 'y');
    init(B, 'o');
    init(F, 'r');
    init(L, 'g');
    init(R, 'b');

    int c;
    cin >> c;
    while (c--) {
      string s;
      cin >> s;
      char side = s[0];
      bool clockwise = s[1] == '+';
      // cout << side << " " << clockwise << "\n";
      if (side == 'U') {
        rotate_U(clockwise);
        // printSide(U);
      }
      if (side == 'D') {
        rotate_D(clockwise);
        // printSide(D);
      }
      if (side == 'F') {
        rotate_F(clockwise);
        // printSide(B);
      }
      if (side == 'R') {
        rotate_R(clockwise);
        // printSide(B);
      }
      if (side == 'B') {
        rotate_B(clockwise);
        // printSide(B);
      }
      if (side == 'L') {
        rotate_L(clockwise);
        // printSide(B);
      }
    }

    // printSide(U);
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        cout << U.b[i][j];
      }
      cout << '\n';
    }
  }
  
  return 0;
}