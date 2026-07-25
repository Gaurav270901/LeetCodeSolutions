class Solution {
    // store the count of chars in map then for each count get the total even charater you can get from the freq add that in result and at the end of the result add one in it as in palindrome we can keep one odd character in the middle , but we also need to track if there is any odd freq present or not then and only then we will add in in our ans 
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq ;
        int ans = 0 ;
        bool isOddFreqPresent = false ;

        for(auto i : s){
            freq[i]++;
        }

        for(auto i : freq){
            int count = i.second ;
            if(count % 2 != 0 ){
                ans += (count-1);
                isOddFreqPresent = true ;
            }
            else{
                ans += count ;
            }
        }

        return (isOddFreqPresent == true) ? ans + 1 : ans ;
    }
};