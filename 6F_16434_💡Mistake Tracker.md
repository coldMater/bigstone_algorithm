### Data type comparison

I defined the monster's health as an int because the problem stated its maximum value to be 1,000,000. The hero's initial attack power is also 1,000,000, but after passing through around 100,000 (10^6) rooms, the attack power can exceed the range of an int. Therefore, if the monster's health were defined as an int, there would be a risk of underflow caused by the attack power within the long long range, making it difficult to correctly determine whether the monster's health had dropped below zero.

### Optimization to O(1) using mathematical formula

Running the battle scenario as described in the problem using a for loop results in a time limit exceeded (TLE) error. This can be optimized to O(1) by applying a mathematical formula.
