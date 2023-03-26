#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void printVector (vector<int> v) {
    for (auto i : v) {
        cout << i << " " ;
    }
    cout << endl;
}

int main () {
    vector<int> v = { 1, 2, 3 };

    // [1,2,3] -> next_permutation -> lexicographically ascending order 
    do {
        printVector(v);
    } while (next_permutation(v.begin(), v.end()));

    v.clear();
    cout << endl;

    // The direction of the sequence can affect the order 
    // in which the permutations are generated.
    // If the initial sequence is in descending order,
    // prev_permutation will generate the previous permutation in ascending order.
    // If the initial sequence is in ascending order,
    // prev_permutation will generate the previous permutation in descending order.

    // [2,3,1] -> next_permutation -> [3,1,2]
    // It rearranges the elements in the vector(or array) to generate the next lexicographically greater permutation.
    int a[3] = { 2, 3, 1 };
    next_permutation(a, a + 3);
    cout << a[0] << a[1] << a[2] << endl;

    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    
    // [3,2,1] -> prev_permutation -> lexicographically descending order 
    do {
        printVector(v);
    } while (prev_permutation(v.begin(), v.end()));

    return 0;
}