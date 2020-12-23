https://www.geeksforgeeks.org/stdstring-class-in-c/



1)  std::string base="this is a test string.";
  std::string str2="n example";
  std::string str3="sample phrase";
  std::string str4="useful.";

  // replace signatures used in the same order as described above:

  // Using positions:                 0123456789*123456789*12345
  std::string str=base;           // "this is a test string."
  str.replace(9,5,str2);          // "this is an example string." (1)
  str.replace(19,6,str3,7,6);     // "this is an example phrase." (2)
str.replace(str.begin(),str.end()-3,str3);                    // "sample phrase!!!"      (1)
  str.replace(str.begin(),str.begin()+6,"replace"); 







2)   std::string str="to be question";
  std::string str2="the ";
  std::string str3="or not to be";
  std::string::iterator it;

  // used in the same order as described above:
  str.insert(6,str2);                 // to be (the )question
  str.insert(6,str3,3,4);             // to be (not )the question
  str.insert(10,"that is cool",8);    // to be not (that is )the question
  str.insert(10,"to be ");            // to be not (to be )that is the question
  str.insert(15,1,':');               // to be not to be(:) that is the question
  it = str.insert(str.begin()+5,','); // to be(,) not to be: that is the question
  str.insert (str.end(),3,'.');       // to be, not to be: that is the question(...)
  str.insert (it+2,str3.begin(),str3.begin()+3); // (or )







3) Check if given string is substring of another string






4)  Count the Number of Consistent Strings : A string is consistent if all characters in the string appear in the string allowed.
  Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
  
  
  
  NOTE : String can be treated as an  array of size 26
    
    
    
    
    int countConsistentStrings(string allowed, vector<string>& words) {
        // support variable
        int res = words.size();
        bool alpha[26] = {};
        // populating alpha
        for (char c: allowed) alpha[c - 'a'] = true;      // converting char to int so that can be indexed in array
        // parsing all the words to see if each character is in alpha
        for (string word: words) {
            // in case we find an unallowed character, we decrease res and break
            for (char c: word) if (!alpha[c - 'a']) {
                res--;
                break;
            }
        }
        return res;
    }






NOTE:  to avoid having to compute c - 'a' too many times in above solution



int countConsistentStrings(string allowed, vector<string>& words) {
        // support variable
        int res = words.size();
        bool alpha[123] = {};
        // populating alpha
        for (char c: allowed) alpha[c] = true;
        // parsing all the words to see if each character is in alpha
        for (string word: words) {
            // in case we find an unallowed character, we decrease res and break
            for (char c: word) if (!alpha[c]) {
                res--;
                break;
            }
        }
        return res;
    }
    









5)   String comparison:
str1 == str2     



6) String Initialization :
string first(""), second("");      // first="", second=""





    
7) String Searching : KMP algorithm : Given  strings (pattern) and (text), find the number of occurrences of pattern in text.



8) Z-algorithm : Z algorithm is a linear time string matching algorithm which runs in  complexity. 
  It is used to find all occurrence of a pattern  in a string , which is common string searching problem.
  
  
  
  
  9) Manchars algorithm : It is used to find the Longest Palindromic Sub-string in any string. This algorithm is required to solve sub-problems of some very hard problems. 
    
