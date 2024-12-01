🚩 challenge: Post about why this problem is related to parametric search, and explore it together with a graph (including the "Cutting Trees" problem, 2805).

```cpp
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> cs[i];
    largest = max(cs[i], largest);
  }

  for (int j = 1; j <= largest; ++j) {
    int sc = 0;
    for (int i = 0; i < M; ++i) {
      sc += cs[i] / j; // student count
      if (cs[i] % j != 0) sc += 1; // when a remaining jewel exists
      // cout << "sc: " << sc << "\n";
    }
    cout << "jealousy: " << j << ", number of students: " << sc << "\n";
  }
```

The output of the code above is as follows:
(It can be observed that the dependent variable, the number of students, changes linearly according to the variable of jealousy, providing a basis for parametric search.)

```text
jealousy: 1, number of students: 23
jealousy: 2, number of students: 13
jealousy: 3, number of students: 11
jealousy: 4, number of students: 7
jealousy: 5, number of students: 7
jealousy: 6, number of students: 7
jealousy: 7, number of students: 5
```
