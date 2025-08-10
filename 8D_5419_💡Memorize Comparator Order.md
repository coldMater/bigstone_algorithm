> It should return true if the first argument should come before the second; otherwise, it should return false.
>
> - https://www.geeksforgeeks.org/cpp/sort-c-stl/

```cpp

bool comp (int first, int second) {
  // return true if the first argument should come before the second;
  // otherwise, it should return false. - https://www.geeksforgeeks.org/cpp/sort-c-stl/

  // The default operator is '<'.
  // If "first < second" is true, it means "first" should be on the left and "second" should be on the right.
}

sort(a.begin(), a.end(), comp)
```
