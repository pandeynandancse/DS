1. a>>1       i.e.      a/2
   a>>2       i.e.      a/4
   a<<1       i.e.      a*2
   
   
  
2. a XOR b               a ^ b


3. & | ~ ^             bitwise operators


4.  Binary to Integer >     head->101     >    head->1->0->1      >     linked list      >    multiply by 2 and add current value

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int  res =0;
        while(head){
            
            res = (res << 1) ;
            cout<<res<<" ";
                res= res+head -> val;
            cout<<res<<" ";
            head=head->next;
            cout<<res<<" ";
            cout<<"\n";
            
        }
        return res;
    }
};
    
    
    
    
    
    
 
5.  Hamming Distance  > The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
                      > use XOR 
                      > use bitset to convert  integers into an array of bits 
                      
                      
                      
                      Approach1-1 => int hammingDistance(int x, int y) {
                                            int ans = 0;

                                        // Bitset for x integer
                                            bitset<32> a(x);
                                        // Bitset for y integer
                                            bitset<32> b(y);

                                        // iterate through bits
                                            for(int i = 0; i < 32; i++){
                                        // if bit at i is not equal in the bitsets, increment the answer
                                                if(a[i] != b[i]) ans++;
                                            }

                                       // return the answer
                                            return ans;
                                        }
                                        
                                        
                                        
                                        
                                        
                         Approach-2 => int hammingDistance(int x, int y) {
                                            int res=x^y;                   // res=5
                                            bitset<32>a(res);                     //for(int i=0;i<32;i++){ cout<<a[i]; } //10100000000000000000000000000000
                                            return a.count();
                                        }
