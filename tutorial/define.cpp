#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592 // define constant
#define loop(x, n) for(int x = 0; x < n; x++) // define macro

int main() {
    cout << PI << "\n";
    int sum = 0;
    loop(i, 10) {
        sum += i;
    }
    cout << sum << '\n';
    return 0;
}
