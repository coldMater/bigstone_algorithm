#include <bits/stdc++.h>
using namespace std;

void printArr(int a[20][20]) {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n" << flush;
    }

}

void printArrAsHex(int a[20][20]) {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            printf("%x ", a[i][j]);
        }
        cout << "\n" << flush;
    }

}

void printCharArr(char a[20][20]) {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n" << flush;
    }

}

int main () {
    // ==*== 2D array initialize using function fill()

    // Before initialization, each element of the array contains a garbage value,
    // which can be any arbitrary value that happened to be in memory at the time of declaration.
    int a[20][20];

    printArr(a);

    // Using the fill() method, you can assign any value to every element in the array.
    fill(&a[0][0], &a[0][0] + (20 * 20), 4321);

    printArr(a); // 4321 4321 4321 ...

    // ==*== 2D array initialize using memset()

    // USING memest() TO SET ALL BITS OF A MEMORY BLOCK TO 1
    // When using memset to initialize a block of 4-byte integers with a negative value such as -1,
    // each integer will be set to the maximum value of 0xFFFFFFFF,
    // which corresponds to all bits being set to 1.
    // This can be useful for setting all bits of a memory block to 1 when using 4-byte integers.
    memset(a, -1, sizeof(a)); // sizeof(a) is 1600(= 40 x 40). Size of 2D array automatically calculated by function sizeof(a).
    printArr(a);

    // USING memest() TO SET ALL BITS OF A MEMORY BLOCK TO 0
    // When using memset, the assigned value must be 0 or 1. 
    memset(a, 0, sizeof(a));
    printArr(a);

    int c[20][20]; // An unexpected value would be assigned. 
    printArr(c);
    // The memset function sets every block of the c memory array to the value 0x01, 
    // which means that each 4-byte integer in the array will have a value of 0x01010101. 
    // When interpreted as a decimal value, this is equivalent to 16843009.
    memset(c, 1, sizeof(c));
    printArr(c);

    // Using memset to initialize a memory block of integers in the array d with the value 0xaa will set each byte of the memory block to 0xaa.
    // Each 4-byte integer element in the d array will then have the value 0xaaaaaaaa. (which is 0xaa repeated 4 times.)
    int d[20][20];
    memset(d, 0xaa, sizeof(d));
    printArrAsHex(d); // aaaaaaaa aaaaaaaa aaaaaaaa ...

    // For char arrays, values such as 'a', 'b', 'c' are also possible.
    int e[20][20];
    memset(e, 'a', sizeof(e));
    printArrAsHex(e); // 61616161 61616161 ... -> The output will be a series of hexadecimal values, such as 0x61616161, which represent the ASCII code for the character 'a' (97 in decimal)

    int f[20][20];
    // Using memset() with a value of 256 will cause an integer overflow,
    // resulting in the value being truncated to 0. 
    // As a result, every element in the array will be assigned the value of 0.
    memset(f, 256, sizeof(f)); // 0 0 0 0 ... -> 

    printArr(f);
    return 0;
}