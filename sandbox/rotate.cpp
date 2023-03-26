#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v) {
    for (auto n : v) {
        cout << n << " ";
    }
    cout << endl;
}

int main () {
    vector<int> v;
    for (int i = 1; i < 10; i++) v.push_back(i);

    // rotate(first, middle, last)
    // Rotate: detach the element pointed to by middle and attach it to first
    rotate(v.begin(), v.begin() + 1, v.end()); // 2 3 4 5 6 7 8 9 1
    print(v);
    rotate(v.begin(), v.begin() + 1, v.end()); // 3 4 5 6 7 8 9 1 2 
    print(v);
    rotate(v.begin(), v.begin() + 1, v.end()); // 4 5 6 7 8 9 1 2 3  
    print(v);

    // initialize
    cout << endl;
    v.clear();
    for (int i = 1; i < 10; i++) v.push_back(i);

    // The elements in the range `[v.end()-1, v.end())` are detached and attached to `v.begin()`, resulting in a rotation that appears to move the last element to the first position.
    rotate(v.begin(), v.end() - 1, v.end()); // 9 1 2 3 4 5 6 7 8 
    print(v);
    rotate(v.begin(), v.end() - 1, v.end()); // 8 9 1 2 3 4 5 6 7
    print(v);
    rotate(v.begin(), v.end() - 1, v.end()); // 7 8 9 1 2 3 4 5 6
    print(v);

    // initialize
    cout << endl;
    v.clear();
    for (int i = 1; i < 10; i++) v.push_back(i);

    rotate(v.begin(), v.begin() + 3, v.end()); // [1,2,3],4,5,6,7,8,9 Surrounded by `[]` is rotated at once, resulting in the new sequence `[4, 5, 6, 7, 8, 9, 1, 2, 3]`.

    print(v);

    return 0;
}