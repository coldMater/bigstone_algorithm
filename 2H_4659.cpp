// https://www.acmicpc.net/problem/4659
#include <bits/stdc++.h>
using namespace std;

string s;
char vowels[] = {'a','e','i','o','u'};

bool isVowel (char c) {
    for (int i = 0; i < 5; ++i) {
        if (c == vowels[i]) return true;
    }
    return false;
}

void printIsNotAcceptable(string s) {
    cout << "<" << s << ">" <<  " is not acceptable." << "\n";
}

void printIsAcceptable(string s) {
    cout << "<" << s << ">" <<  " is acceptable." << "\n";
}

int main () {
    while (true) {
        cin >> s;
        if (s == "end") break;

        // Rule 1
        int vc = 0; // vowels count
        for (char c : s) {
            if (isVowel(c)) vc++;
        }
        if (vc == 0) {
            printIsNotAcceptable(s);
            continue;
        }

        // Rule 2
        char prevVorC = '0'; // previous Vowel or Consonent
        int cc = 0; // consecutive count 
        for (char c : s) {
            char temp; // vowel - 'v' or consonant - 'c'
            if (isVowel(c)) {
                temp = 'v';
            } else {
                temp = 'c';
            }
            if (prevVorC == temp) { 
                cc++;
            } else {
                cc = 1;
            }
            prevVorC = temp;
            if (cc >= 3) break;
        }
        if (cc >= 3) {
            printIsNotAcceptable(s);
            continue;
        }

        // Rule 3
        bool r3p = true; // rule 3 passed?
        for (int i = 0; i < s.size() - 1; ++i) {
            char first = s[i];
            char second = s[i + 1];

            if (first == 'o' && second == 'o') continue;
            if (first == 'e' && second == 'e') continue;
            if (first == second) {
                printIsNotAcceptable(s);
                r3p = false;
                break;
            }
        }

        if (r3p) {
            printIsAcceptable(s);
        }
    }
    return 0;
}