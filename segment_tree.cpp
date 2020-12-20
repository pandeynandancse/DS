https://cp-algorithms.com/data_structures/segment_tree.html
https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/





A Segment Tree is a data structure that allows answering range queries over an array effectively, 
while still being flexible enough to allow modifying the array. This includes finding the sum of consecutive array elements a[l…r],
or finding the minimum element in a such a range in O(logn) time.
Between answering such queries the Segment Tree allows modifying the array by replacing one element, 
or even change the elements of a whole subsegment (e.g. assigning all elements a[l…r] to any value, or adding a value to all element in the subsegment).





One important property of Segment Trees is, that they require only a linear amount of memory. The standard Segment Tree requires 4n vertices for working on an array of size n.




Representation of Segment trees
1. Leaf Nodes are the elements of the input array.
2. Each internal node represents some merging of the leaf nodes. The merging may be different for different problems.





Like Heap, the segment tree is also represented as an array. The difference here is, it is not a complete binary tree.
It is rather a full binary tree (every node has 0 or 2 children) and all levels are filled except possibly the last level.
Unlike Heap, the last level may have gaps between nodes. 





Example 1: segment-tree-set-1-sum-of-given-range :
Solution : For this problem, merging is sum of leaves under a node.







