#include <bits/stdc++.h>
using namespace std;

vector<int> v;
main () {
    for (int i = 0; i < 5; i++) {
        v.push_back(i);
        v.push_back(i);
    }

    cout << v.end().base() << "\n"; // result A
    auto afterUniqueLastIterator = unique(v.begin(), v.end());
    // Duplicated value removed from `v`.
    // end last iterator fo 'v' returned to 'afterUniqueLastIterator'.
    // Left other values are reamined as it was. (Memory space of 'v' does not changed. Front part of the memory has changed to unique values. But leftover doesn't.)
    cout << v.end().base() << "\n"; // same as result A

    cout << afterUniqueLastIterator - v.begin() << '\n'; // 5

    for (int i : v) cout << i; // 0123423344
    cout << '\n';
    v.erase(afterUniqueLastIterator, v.end());
    for (int i : v) cout << i; // 01234


    return 0;
}