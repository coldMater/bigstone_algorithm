```cpp
#include <stdio.h>
// int main () {
//   long long a = 1;
//   while (true) {
//     a = a << 1;
//     printf("%lld\n", a);
//     if (a == 0) break;
//   }
// }

int main () {
  for (int i = 0; i < 34; ++i) {
    // printf("%d\n", (1 << i)); // 32-bit integer
    // printf("%d\n", (1L << i)); // 32-bit integer
    // printf("%lld\n", (1ll << i)); // 64-bit integer
    printf("%lld\n", (1LL << i)); // 32bit integer ⚠️ 64bit long long literal in C++: use `ll` or `LL`
  }
}
```
