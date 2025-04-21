// https://school.programmers.co.kr/learn/courses/30/lessons/60057
#include <bits/stdc++.h>
using namespace std;

int bs;
int board[60][60];
int tb[60][60]; // temp board
void pb (int board[20][20]) {
    for (int i = 0; i < bs; ++i) {
        for (int j = 0; j < bs; ++j) {
            cout << board[i][j] << " ";
        }
         cout << "\n";
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bs = lock.size() + (key.size() - 1) * 2; // board size
    
    int lockStart = key.size() - 1;
    int lockEnd = lockStart + lock.size() - 1;
    for (int i = lockStart; i <= lockEnd; ++i) {
        for (int j = lockStart; j <= lockEnd; ++j) {
            board[i][j] = lock[i - lockStart][j - lockStart];
            // cout << board[i][j] << " ";
        }
        // cout << "\n";
    }
    
    // set key
    int keyStart = 0;
    int keyEnd = bs - (key.size() - 1);
    
    int tk[key.size()][key.size()]; // temp key
    for (int i = 0 ; i < key.size(); ++i) {
        for (int j = 0; j < key.size(); ++j) {
            tk[i][j] = key[i][j];
        }
    }
    int rk[key.size()][key.size()]; // rotated key
    // rotate key
    for (int t = 0; t < 4; ++t) {
        for (int y = 0; y < key.size(); ++y) {
            for (int x = 0; x < key.size(); ++x) {
                rk[y][x] = tk[key.size() - 1 - x][y];
            }
        }
        
        // for (int i = 0; i < key.size(); ++i) {
            // for (int j = 0 ; j < key.size(); ++j) {
                // cout << rk[i][j] << " ";
            // }
            // cout << "\n";
        // }
        
        // check key
        {
            for (int i = 0; i < bs - (key.size() - 1); ++i) {
                for (int j = 0; j < bs - (key.size() - 1); ++j) {
                    memcpy(tb, board, sizeof(board));
                    for (int ky = 0; ky < key.size(); ++ky) {
                        for (int kx = 0; kx < key.size(); ++kx) {
                            tb[i + ky][j + kx] ^= rk[ky][kx];
                        }
                    }
                    // pb(tb);
                    // check
                    bool result = true;
                    for (int ly = lockStart; ly <= lockEnd; ++ly) {
                        for (int lx = lockStart; lx <= lockEnd; ++lx) {
                            result &= tb[ly][lx];
                        }
                    }
                    if (result == true) return true;
                    // cout << "result: " << result << "\n";
                    // cout << "\n";
                }
            }
        }
            
        // cout << "\n";
        memcpy(tk, rk, sizeof(tk));
    }
    
    
    
    bool answer = false;
    return answer;
}