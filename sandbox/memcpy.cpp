#include<bits/stdc++.h>
using namespace std;

void printArr(int* arr, int size) {
    int len = size / sizeof(int);
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
}

int main() {
    int a[5], b[5];
    for (int i = 0; i < 5; i++) a[4 - i] = i*i*i*i;

    memcpy(b, a, sizeof(a));

    printArr(a, sizeof(a));
    printArr(b, sizeof(b));

    for (int z : a) {

    }

    return 0;
}