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



















6. These are four important built-in functions in GCC compiler:
    Similarly you can use __builtin_popcount(x) , __builtin_popcountl(x) & __builtin_popcountll(x) for long and long long data types.  >  This function is used to count the number of one’s(set bits) in an integer.
    Similarly you can use __builtin_parity(x) , __builtin_parityl(x) & __builtin_parityll(x) for long and long long data types. >   This function returns true(1) if the number has odd parity else it returns false(0) for even parity.
    Similarly you can use __builtin_clz(x) , __builtin_clzl(x) & __builtin_clzll(x) for long and long long data types.    >   This function is used to count the leading zeros of the integer.   
     Similarly you can use __builtin_ctz(x) , __builtin_ctzl(x) & __builtin_ctzll(x) for long and long long data types.
       
       

       
       
7.  sort(arr, arr + n, greater<int>());             // descending order


bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
int main()
{
    Interval arr[] = { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n, compareInterval);
    for (int i = 0; i < n; i++)
        cout << "[" << arr[i].start << "," << arr[i].end << "] ";
    return 0;
}






8. Sort Integers by The Number of 1 Bits

vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b){
                        int x = __builtin_popcount(a);
                        int y = __builtin_popcount(b);
                        return x==y ? a<b : x<y;                   
        });
            for(int i=0; i<arr.size(); i++){
                cout<<arr[i]<<" ";
            }
        return arr;
    }
    







9. no. of set bits   >   alternate of builtin-popcount
int setbits(int n) {
        int setbit = 0;
        while (n) {
            n &= n-1;
            ++setbit;
        }
        return setbit;
    }
    






10.
   int findComplement(int num) { 
	int numberOfBits = (int)log2(num) + 1;
	return pow(2,numberOfBits) - num - 1;
}




11. even number  > if( (num & 1) == 0))
   
   
   
12.      num=5
        bitset<32> a(num);            //a = 10100000000000000000000000000000
         a.to_ulong();            // 5
