An int type variable can be utilized as a flag storage to remember visited alphabets.
From A to Z, a total of 26 alphabets can be toggled on or off as flags.

### To activate the flag corresponding to the n-th alphabet
```cpp
a |= 1 << n;
```

### To deactivate the flag corresponding to the n-th alphabet
```cpp
a &= ~(1 << n);
```

### To check whether the flag for the n-th alphabet is activated.
```cpp
if (a & (1 << n)) { /* when n-th flag activated */ }
```
