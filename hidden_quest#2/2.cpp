// https://school.programmers.co.kr/learn/courses/30/lessons/60059
#include <bits/stdc++.h>
using namespace std;

void p(vector<string>& ss) {
    for (string s : ss) {
        cout << s << " ";
    }
    cout << "\n";
}

int solution(string s) {
    if (s.length() == 1) {
        return 1;
    }
    
    vector<string> ss;
    int mn = 123'456'789'0;
    for (int ln = 1; ln <= s.length() / 2; ++ln) {
        int cur = 0;
        string ts = "";
        while (cur < s.length()) {
            ts += s[cur];
            if (ts.length() == ln) {
                ss.push_back(ts);
                ts = "";
            }
            cur++;
        }
        if (ts.length() != 0) ss.push_back(ts);
        // p(ss);
        
        string prev = ss[0];
        int cnt = 0;
        string cmpl = "";
        for (int i = 1; i < ss.size(); ++i) {
            if (prev == ss[i]) {
                cnt++;
            } else {
                cmpl += (cnt != 0 ? to_string(cnt + 1) : "") + prev;
                prev = ss[i];
                cnt = 0;
            }
        }
        cmpl += (cnt != 0 ? to_string(cnt + 1) : "") + prev;
        // cout << cmpl << "\n";
        mn = min(mn, int(cmpl.length()));
        
        ss.clear();
    }
    
    int answer = mn;
    return answer;
}