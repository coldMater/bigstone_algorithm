#include<bits/stdc++.h>
using namespace std;
int T;
string s;

int main() {
    cin >> T;
    string bufferflush;
    getline(cin, bufferflush);
    for (int i = 0; i < T; i++) {
        getline(cin, s); // 맨 처음 루프(i = 0) 때는 이 부분이 동작하지 않는 것처럼 보인다.
        cout << s << "\n";
    }
    cout << string::npos << '\n';
    return 0;
}