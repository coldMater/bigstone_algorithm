// https://www.acmicpc.net/problem/16637
#include <bits/stdc++.h>
using namespace std;

int N;
string s;
vector<char> ops;
vector<int> nums;
int m; // max

int calc (int a, int b, char op) {
    int result = 0;
    if (op == '+') result = a + b;
    if (op == '-') result = a - b;
    if (op == '*') result = a * b;
    
    // cout << a << op << b << "=" << result << "\n";
    return result;
}

void go (int s, int prev) {
    if (s >= (int)ops.size()) {
        m = max(prev, m);
        return;
    }
    // s + 1
    go(s + 1, calc(prev, nums[s + 1], ops[s]));

    if (s + 2 <= ops.size()) {
        go(s + 2, calc(prev, calc(nums[s + 1], nums[s + 2], ops[s + 1]), ops[s]));
    }
}

int main () {
    cin >> N;
    cin >> s;
    m = -pow(2, 31);
    for (char c : s) {
        if (c == '+' || c == '-' || c == '*') {
            ops.push_back(c);
            continue;
        }
        nums.push_back(c - '0');
    }

    go(0, nums[0]);

    cout << m;

    return 0;
}