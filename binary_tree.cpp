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





TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& pstart, int pend, int istart, int iend)
    {
        //Is inorder index invalid? have we reach num element in preorder?
        if(istart > iend || iend < istart || pstart == pend)
            return NULL;
        
        
        //Construct a new node from preorder
        TreeNode* node = new TreeNode(preorder[pstart]);      

        
        //Find the element in inorder array.
        int in = istart;
        while( in < iend && inorder[in] != preorder[pstart])
            in++;
        
        //Move to the next element in preorder.
        pstart++;
        
        //Left subtree is from istart till in-1
        node->left = build( preorder, inorder, pstart, pend, istart, in-1);
        
        //right subtree is from in+1 till iend
        node->right = build(preorder, inorder, pstart, pend, in+1, iend);        
        return node;
    }


------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
  9) Construct Binary Tree from Inorder and Postorder Traversal
  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
  10) Binary Tree Level Order Traversal
  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
  11) Construct Binary Search Tree from Preorder Traversal
  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  12) Longest ZigZag Path in a Binary Tree
  
