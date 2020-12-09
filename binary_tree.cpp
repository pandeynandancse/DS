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
    
