#include <bits/stdc++.h>
using namespace std;

void print2DVector (vector<vector<int>> v) {
    for (auto r : v) {
        for (auto n : r) {
            printf("%2d",  n);
        }
        cout << endl;
    }
}

void rotate90(vector<vector<int>> &v) {
    vector<vector<int>> temp;
    for (int i = 0; i < v.size(); ++i) {
        vector<int> row;
        for (int j = 0; j < v[i].size(); ++j) {
            row.push_back(0);
        }
        temp.push_back(row);
    }

    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            temp[i][j] = v[v.size() - j - 1][i];
        }
    }

    v = temp;
}

int main () {
    vector<vector<int>> v = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    print2DVector(v);
    cout << endl;
    rotate90(v);
    print2DVector(v);
    return 0;
}