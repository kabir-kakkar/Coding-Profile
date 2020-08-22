Given a tree of n even nodes. 
The task is to find the maximum number of edges to be removed from the given tree to obtain forest of trees having even number of nodes. 
This problem is always solvable as given graph has even nodes.

Input : 

n = 10
Edge 1: 1 3
Edge 2: 1 6
Edge 3: 1 2
Edge 4: 3 4
Edge 5: 6 8
Edge 6: 2 7
Edge 7: 2 5
Edge 8: 4 9
Edge 9: 4 10

Output : 2
By removing 2 edges, we can obtain the forest with even node tree.

Procedure:

1. Find a subtree with even number of nodes and remove it from rest of tree by removing the edge connecting it. 
2. After removal, we are left with tree with even node only because initially we have even number of nodes in the tree and removed subtree has also even node.
3. Repeat the same procedure until we left with the tree that cannot be further decomposed in this manner.
4. To do this, the idea is to use Depth First Search to traverse the tree. 
5. Implement DFS function in such a manner that it will return number of nodes in the subtree whose root is node on which DFS is performed. 
6. If the number of nodes is even then remove the edge, else ignore.

