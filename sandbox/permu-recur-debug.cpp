#include <bits/stdc++.h>
using namespace std;

int a[3] = {1, 2, 3};
int n = 3, r = 3; // r을 바꿔가면서 연습해보세요. :)

void print() {
    for (int i = 0; i < r; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void makePermutation(int n, int r, int depth) {
    if (r == depth) {
        print();
        return;
    }

    for (int i = depth; i < n; i++) {
        cout << i << " : " << depth << "를 바꾼다!\n";
        swap(a[i], a[depth]);
        makePermutation(n, r, depth + 1);
        cout << i << " : " << depth << "를 다시 바꾼다!\n";
        swap(a[i], a[depth]);
    }

    return;
}

int main() {
    makePermutation(n, r, 0);
    return 0;
}
