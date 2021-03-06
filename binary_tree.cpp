1) 
  void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        
    }
    
    
    
 ------------------------------------------------------------inorder/preorder/postorder---------------------------------------------------------------------   
    
         
2)  >>>> Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
    >>>> Catalan Number = 1,1,2,5,14, 42, 132, 429 ,.......................
    >>>>(2nCn)n+1 = (2n)!/(n+1)!(n)!
    >>>> ((ab)c)d     (a(bc))d     (ab)(cd)     a((bc)d)     a(b(cd)) => association
    >>>> ((()))     ()(())     ()()()     (())()     (()())
    >>>> XXXYYY     XYXXYY     XYXYXY     XXYYXY     XXYXYY
    >>>> No. of ways going from one end to other end of diagonal but without using diagonal path => https://en.wikipedia.org/wiki/File:Catalan_number_4x4_grid_example.svg
    >>>> left-of-root = 5 unique elems
         right-of-root = 5 unique elems
         then root can be arranged in 5*5 different forms
    
    >>>> Cn = nSIGMAi=0(Ci * Cn-i-1) >>> here DP can be uses because future value(Cn) is dependent on Previous Value(Ci and Cn-i-1)
    
    
 --------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
3) Catalan Number DP : 
unsigned long int catalanDP(unsigned int n) 
{ 
    unsigned long int catalan[n + 1]; 
    catalan[0] = catalan[1] = 1; 
    for (int i = 2; i <= n; i++)  
    { 
        catalan[i] = 0; 
        for (int j = 0; j < i; j++) 
            catalan[i] += catalan[j]  
                       * catalan[i - j - 1]; 
    } 
    return catalan[n]; 
} 


4)Catalan Number  Recursive Number
  unsigned long int catalan(unsigned int n) 
{  
    if (n <= 1) 
        return 1; 
    unsigned long int res = 0; 
    for (int i = 0; i < n; i++) 
        res += catalan(i)  
            * catalan(n - i - 1); 
    return res; 
} 


5) Catalan Number  Coefficient Method
unsigned long int binomialCoeff(unsigned int n, 
                                unsigned int k) 
{ 
    unsigned long int res = 1; 
    if (k > n - k) 
        k = n - k; 
  // Calculate value of [n*(n-1)*---*(n-k+1)] / 
    // [k*(k-1)*---*1] 
    for (int i = 0; i < k; ++i) { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
    return res; 
} 
unsigned long int catalan(unsigned int n) 
{ 
    unsigned long int c = binomialCoeff(2 * n, n); 
    return c / (n + 1); 
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
  6) Factorial of Number Using Recursion :  

                  long int multiplyNumbers(int n) {
                      if (n>=1)
                          return n*multiplyNumbers(n-1);
                      else
                          return 1;
                  }





----------------------------------------------------------------------------------------------------------------------------------------------------------------------

7)   Factorial of  Number Using DP:

                  int fact(int n) {
                     if (n >= 0) {
                        result[0] = 1;
                        for (int i = 1; i <= n; ++i) {
                           result[i] = i * result[i - 1];
                        }
                        return result[n];
                     }
                  }


----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
8) Construct Binary Tree from Preorder and Inorder Traversal : 





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
   TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& pstart,int  pend , int istart,int iend){
        if(pstart==pend || istart>iend){
            return NULL;
        }  
        TreeNode* node = new TreeNode(preorder[pstart]);
        
        int val = preorder[pstart];
        int in =0;
        
        while(in<iend && inorder[in]!=val){
            in++;
        }
        pstart = pstart + 1;
        
        node->left = build(preorder, inorder, pstart, pend, istart, in-1);
        node->right= build(preorder, inorder, pstart, pend, in+1, iend);
        return node;
            
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pstart =0;
        return build(preorder, inorder, pstart, preorder.size() , 0 , inorder.size());
    }
};


------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
  9) Construct Binary Tree from Inorder and Postorder Traversal
  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
  10) Binary Tree Level Order Traversal
  
  
  vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> t;
            
            int s= q.size();
            while(s-->0){
                TreeNode* r = q.front();
                q.pop();
                t.push_back(r->val);
                if (r->left != nullptr) 
                    q.push(r->left);
                
                if (r->right != nullptr)
                    q.push(r->right);
            }
            ans.push_back(t);
            
        }
       # reverse(res.begin(),res.end()); >>>> Level order traversal 2
        return ans;
    }
    
  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
  11) Construct Binary Search Tree from Preorder Traversal
  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  12) Longest ZigZag Path in a Binary Tree  >>> Also print that  nodes (pending)
  
  
  
  
  
  
  pair<int, int> traverse(TreeNode* node, int &ans) {
        if (!node) return {-1, -1};
        
        auto left = traverse(node->left, ans);
        auto right = traverse(node->right, ans);
        
        pair<int, int> ret = {left.second + 1, right.first + 1};
        
        ans = max({ans, ret.first, ret.second});
        return ret;
    }
    
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        
        int ans = 0;
        traverse(root, ans);
        
        return ans;
    }


-----------------------------------------

13) Unique Binary Search Trees II

-----------------------------

14) CRUD in BST

------------

15) CRUD in Binary Tree


-------

16) Inorder Successor in BST


-------------

17) Smallest String Starting From Leaf

18) Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree



19) Construct Binary Tree from String

20) Max height of binary tree

    if(root){
            return 1+ max(maxDepth(root->left), maxDepth(root->right));
        }
        else{
            return 0;
        }
    
    
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  21) Min height of Binary Tree
  
  
      int minDepth(TreeNode root) {
          if(root==NULL)
          return 0;
          if(root->left==NULL)
          return 1+minDepth(root->right);
          if(root->right==NULL)
          return 1+minDepth(root->left);
          return 1+min(minDepth(root->left),minDepth(root->right));

      }
      


-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  22) ZigZag level order traversal
  
  
--------------------------------------------------------------------------------------------------------------------------------------------------------
  
23) Longest path in tree > Diameter of tree




class Solution {
public:
int height(TreeNode *node){
       if (node == NULL)return 0;
       return 1 + max(height(node->left), height(node->right));	
} 
   
   int diameterOfBinaryTree(TreeNode* ptr) {

   if(ptr == NULL) return 0;
   int leftHeight = height(ptr->left);
   int rightHeight = height(ptr->right);
   int leftDiameter = diameterOfBinaryTree(ptr->left);
   int rightDiameter = diameterOfBinaryTree(ptr->right);
   
   return max((leftHeight + rightHeight), max(leftDiameter, rightDiameter));        
       
   }
};






===================================================
  
  
  
  class Solution {
public:
    int check(TreeNode* root,int &ma)
    {   if(root==NULL) return 0;
        int l=check(root->left,ma);
        int r=check(root->right,ma);
        ma=max(ma,(l+r));
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ma=INT_MIN;
        if(root==NULL)  return 0;
        check(root,ma);
        return ma;
    }
};



------------------------------------------------------------------------------------------------------------------------------------------------------------

24) Path In Zigzag Labelled Binary Tree
a) https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/discuss/357749/java-full-explanation-100-beat-in-both
b) https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/discuss/323848/Golang-O(log-n)-with-detail-explanation





vector<int> pathInZigZagTree(int label) {
    int level = log(label) / log(2) + 1;  
    vector<int> path(level);
    while (label) {
        path[level - 1] = label;
        label = pow(2, level) - 1 - label + pow(2, level - 1);
        label >>= 1;
        level--;
    }
    return path;
 }


-----------------------------------------------------------------------------------------------------------------------------------------------------------

25) Maximum Width of Binary Tree



------------------------------------------------------------------

26) Tree to Leaf Longest Path

-----------------------------

27) All paths from tree to leaf




int sumNumbers(TreeNode* root, int number=0) {
        if (root == nullptr) return 0;
        number = number * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr){
            cout << number;
            return 0;
        }
        else{
            sumNumbers(root->left, number);
            sumNumbers(root->right, number);
            return 0 ;
        }  
    }
    


------------------------------------------------------

28) sum-root-to-leaf-numbers 
https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/




 int sumNumbers(TreeNode* root, int number = 0) {
        if (root == nullptr) return 0;
        
        number = number * 10 + root->val;
        
        if (root->left == nullptr && root->right == nullptr)
            return number;
        
        return sumNumbers(root->left, number) + 
               sumNumbers(root->right, number); 
    }
    



-------------------------
  
  29. Merge Tree
 
 
 TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	/*base cases*/
        if(t1==NULL)
            return t2;
        if(t2==NULL)
            return t1;
			
			/*add up the node values of both the tree into t1 's node*/
        t1->val=t1->val+t2->val;
		
		/*call the recursive function for the left subtrees of both the trees*/
        t1->left=mergeTrees(t1->left,t2->left);
		
		/*call the recursive function for the right subtrees of  both the trees*/
        t1->right=mergeTrees(t1->right,t2->right);
		
		/*finally return the merged tree*/
        return t1;
    }
    






----------------------
  
  30. Create right skewed tree from list of nodes > 
  
      TreeNode* new_head = new TreeNode();
      TreeNode* curr = new_head    // curr = [null, 0, null]
        nodes = [1,4,6,8,9];
        for (auto a : nodes) {
            curr->right = new TreeNode(a);
            curr = curr->right;
        }




------------------------
  31. Search in bst
  
  TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL || root->val == val){
            return root;
        }
        else if(root->val > val){
            return searchBST(root->left, val);            
        }
        else{
            return searchBST(root->right, val);            
        }
    }
    

------------------------------------------------
  
  32. Invert/Mirror the Binary tree
  TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* temp = invertTree(root->right);
        root->right= invertTree(root->left);
        root->left = temp;
        return root;
    }
    






Second Solution in another form of above one:
TreeNode* invertTree(TreeNode* root) {
       if(root==NULL)return NULL;

		TreeNode* temp = root->right; //save one side of the tree in a "temp" node;
		root->right = root->left; 
		root->left = temp;

		invertTree(root->left); //call the left side of the tree    // also u can write this but not useful becoz return is NULL  > root->left = invertTree(root->left);
		invertTree(root->right); //call the right side of the tree // also u can write this but not useful becoz return is NULL  > root->right = invertTree(root->right);

		return root;
}





-------------------------------------------
  
  
