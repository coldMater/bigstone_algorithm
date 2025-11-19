To mark that the path has passed through the g-h section, you can perform the following preprocessing:

- Method 1: Double the length of all edges. Then, subtract 1 from the g-h section. After running the shortest path algorithm, if the shortest distance is odd, it means the path has passed through g-h.

(Strictly speaking, since the ratio of distances changes, this preprocessing might affect the shortest path calculation. It needs to be verified whether this preprocessing influences the shortest path calculation or not.)
