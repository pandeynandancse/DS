https://cp-algorithms.com/data_structures/segment_tree.html
https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/

https://visualgo.net/en/segmenttree



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

  
  
class segmentTree {
public:
    int sum, start, end;
    segmentTree *left, *right;
    segmentTree (int start, int end) {
        this->start = start;
        this->end = end;
        this->left = nullptr;
        this->right = nullptr;
        this->sum = 0;
    }
};


class NumArray {
public:
    segmentTree* root = nullptr;
    
    segmentTree* buildTree(vector<int>& nums, int s, int e) {
        if (s > e) {
            return nullptr;
        } else {
            //for range s and e!
            segmentTree* ret = new segmentTree(s, e);
            if (s == e) {  // if only one element in array
                ret->sum = nums[s];
            } else {
                int mid = s  + (e - s) / 2;             
                ret->left = buildTree(nums, s, mid);
                ret->right = buildTree(nums, mid + 1, e);
                //this is the condition where we can change, if we want to evaluate gcd, then instead of sum, we can evaluate gcd of left and right!
                ret->sum = ret->left->sum + ret->right->sum;
            }         
            return ret;
        }
    }
    
  
  
    NumArray(vector<int>& nums) {
        root = buildTree(nums, 0, nums.size() - 1);
    }
  
  
  
    
    void update(int i, int val) {
        update(root, i, val);
    }
    
  
  
  
    void update(segmentTree* root, int pos, int val) {
        if (root->start == root->end) {
           root->sum = val;
        } else {
            int mid = root->start + (root->end - root->start) / 2;
            if (pos <= mid) {
                 update(root->left, pos, val);
            } else {
                 update(root->right, pos, val);
            }
            //this is the condition where we can change, if we want to evaluate gcd, then instead of sum, we can evaluate gcd of left and right!
            root->sum = root->left->sum + root->right->sum;
        }
    }
    
  
  
  
  
    int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }
  
  
  
  
  
    int sumRange(segmentTree* root, int start, int end) {
        if (root->end == end && root->start == start) {
            return root->sum;
        } else {
            int mid = root->start + (root->end - root->start) / 2;
            if (end <= mid) {
                return sumRange(root->left, start, end);
            } else if (start >= mid+1) {
                return sumRange(root->right, start, end);
            }  else {
                return sumRange(root->right, mid+1, end) + sumRange(root->left, start, mid);
            }
        }
    }
};  


























========================================
  faadcoder : https://www.youtube.com/watch?v=Nnb3oggeVQc&ab_channel=faadcoder > segment tree  >> storing as array
  
  
  
