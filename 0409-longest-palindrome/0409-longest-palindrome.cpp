class Solution {
// Count the frequency of each character.
// For every character, we can use all its occurrences if the frequency is even.
//
// If the frequency is odd, we can use (frequency - 1) characters
// to keep the palindrome symmetric and reserve one character.
//
// If at least one character has an odd frequency, we can place
// exactly one odd character at the center of the palindrome,
// so add 1 to the final length.
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq ;
        int palindromeLength  = 0 ;
        bool hasOddFreq = false ;

        for(auto i : s){
            freq[i]++;
        }

        for(auto i : freq){
            int count = i.second ;
            if(count % 2 != 0 ){
                palindromeLength += (count-1);
                hasOddFreq = true ;
            }
            else{
                palindromeLength += count ;
            }
        }

        return hasOddFreq  ? palindromeLength  + 1 : palindromeLength  ;
    }
};