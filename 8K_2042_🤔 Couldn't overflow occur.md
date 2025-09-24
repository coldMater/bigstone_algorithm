# In a Fenwick tree, could the intermediate values exceed the range of long long?

Given the problem constraints, all inputs are within -2^63 to 2^63-1, so I wondered if overflow might occur when sufficiently large inputs are summed together a few times. I even considered whether a data structure beyond long long would be necessary. However, since the answer constraints are also within -2^63 to 2^63-1, we can safely assume that all partial sums will not exceed the range of long long.
