# difference between lower_bound and upper_bound

💡 They do the same job, but the only difference is that **lower_bound includes the target value, while upper_bound excludes it**.

- lower bound: Finds the first position where the value is not less than(= greater than or equal to) the given value
- upper_bound: Finds the first position where the value is "strictly" greater than the given value

```cpp
int arr[5] = { 34, 35, 36, 37, 38 };
cout << *lower_bound(arr, arr + 5, 36); // 36, not less than 36 (= greater than or equal to 36)
cout << "\n";
cout << lower_bound(arr, arr + 5, 36) - arr; // 2
cout << "\n";

cout << *upper_bound(arr, arr + 5, 36); // 37, "strictly" greater than 36
cout << "\n";
cout << upper_bound(arr, arr + 5, 36) - arr; // 3
cout << "\n";

vector<int> arr2 = { 10, 100, 1000, 10000, 100000 };
cout << *lower_bound(arr2.begin(), arr2.end(), 512); // 1000, not less than 512 (= greater than or equal to 512)
cout << "\n";
cout << lower_bound(arr2.begin(), arr2.end(), 512) - arr2.begin(); // 3
cout << "\n";

cout << *upper_bound(arr2.begin(), arr2.end(), 512); // 1000, "strictly" greater than 1000
cout << "\n";
cout << upper_bound(arr2.begin(), arr2.end(), 512) - arr2.begin(); // 3
cout << "\n";
```
