#include <bits/stdc++.h>
using namespace std;

int b[] = {1, 2, 3};
int z[] = {100, 200, 300};
void one (int* a) { // As it is said, asterisk indicates that parameter 'a' is a pointer.
    cout << a << endl;
}

void dot5 (int a) { // a is copy of the original value a
    cout << a << endl; // 1
    a = 4; // Does not affect the original value passed through parameter a.
}

void two (int& a) { // a represents original value a, if it is changed inside the function, the original value will be changed.
    cout << a << endl; // 1
    a = 4; // Affects the original value. Ampersand(&) sign indicates that the function can modify the original value from inside the block of the function.
}

void comp (int* &a) { // The parameter 'a' is a pointer to an integer, and the ampersand(&) sign indicates that the function can modify the original value passed through the parameter. 
    cout << a << endl; // same as result of 'one()' function.

    cout << z << endl;

    a = z;
}

int main () {
    one(b);

    dot5(b[0]);
    cout << b[0] << endl; // 1, which remains unchanged.

    two(b[0]);
    cout << b[0] << endl; // 4, which has been changed to 4 by the function two.

    int* c = b;
    comp(c); // The parameter 'c' is a pointer to an integer. The ampersand(&) sign indicates that the function 'comp(int* &a)' can modify the original pointer passed through the parameter. 
    cout << c[0] << " " << c[1] << " " << c[2] << endl;

    return 0;
}