// https://www.acmicpc.net/board/view/107353
// run at PowerShell on Windows11: `Get-Content .\1B_10808_input.txt | .\1B_10808.exe`

#include<bits/stdc++.h>
using namespace std;

int main() {
    char a = 'a';
    string b;
    
    cin >> b;

    for (char a = 'a'; a <= 'z'; a++) {
        int count = 0;
        for (int i = 0; i < b.length(); i++) {
            if (b[i] == a) count++;
        }
        if (a == 'z') {
            cout << count;
            break;
        }
        cout << count << " ";
    }

    return 0;
}