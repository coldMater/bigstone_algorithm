
#include <bits/stdc++.h>

using namespace std;

bool isRight(string str) {
    stack<char> s;
    
    if (str[0] == ')') return false;
    s.push(str[0]);
    for (int i = 1; i < str.length(); ++i) {
        if (str[i] == '(') {
            s.push(str[i]);
        } else if (str[i] == ')') {
            if (s.top() == '(') {
                s.pop();
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

string solution(string p) {
    if (p == "") return p;
    
    int cur = 0;
    int sum = 0;
    while (cur < p.length()) {
        cout << cur << " ";
        if (p[cur] == '(') sum++;
        if (p[cur] == ')') sum--;
        cur++;
        if (sum == 0) break;
    }
    cout << "\n";
    
    string u = p.substr(0, cur);
    string v = p.substr(cur);
    
    if (isRight(u)) {
        return u + solution(v);
    } else {
        string f = "(" + solution(v) + ")";
        string du = u.substr(1, u.length() - 2);
        // reverse(du.begin(), du.end()); // This is not the intended meaning -> It means to swap `(` <-> `)` with each other
        for (int i = 0; i < u.length(); ++i) {
            du[i] = du[i] == '(' ? ')' : '(';
        }
        return f + du;
    }
}