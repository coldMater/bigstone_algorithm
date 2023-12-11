The conditions specified for the given tree in the problem are as follows.

1. It is connected: for every node you can reach every other node following edges.
2. If an edge is removed, the graph is no longer connected. That is, some nodes cannot be reached anymore.
3. When an edge is added between two existing nodes A and B, a cycle is created. There is a cycle if there is more than one way to go from A to B.

Regarding point 2, the number of edges in the tree must be greater equal than `n - 1`, where n is the number of nodes. 
(The number of edges less than `n - 1` implies that there is at least one unconnected node.)

Regarding point 3, the nuber of edges in the tree must be less equal than `n - 1`, where n is the number of nodes.
(The presence of more than n - 1 edges implies the existence of at least one duplicated edge, leading to the cyclic nature of the graph.)