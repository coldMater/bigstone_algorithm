#include <bits/stdc++.h>
using namespace std;

vector<int> vec[10];
main () {
    for (auto r : vec) {
        r.push_back(11);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            vec[i].push_back(i * 10 + j);
        }
    } 

    for (auto r : vec) {
        for (auto c : r) {
            printf("%03d ", c);
        }
        cout << "\n";
    }

    return 0;
}