A char type variable can be used as an operand of the shift operator.

```cpp
int b = 'c';
int r = 1 << b;

cout << b << "\n"; // 99
cout << r << "\n"; // 8
```