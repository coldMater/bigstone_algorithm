In C++, the equality comparison operator (==) takes precedence over bitwise operators.

In the following code, the precedence of the operators should be considered, taking into account bitwise AND (&) and equality (==). 
However, the equality operator can be omitted and treated using the not operator as follows:
```cpp
// In the code below, it is necessary to consider operator precedence, specifically for the bitwise AND (&) and equality (==) operators
if ((i & 1 << (y * M + x)) == 0) { /* ... */ }

// Simplified with the not operator
if (!(i & 1 << (y * M + x))) { /* ... */ }
```
