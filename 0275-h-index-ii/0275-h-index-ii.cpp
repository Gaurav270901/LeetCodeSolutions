class Solution {
public:
//we need to guess h here which also represent the h books for which researcher got minimum h citation 
//so we will guess number of books and will check if that much book are available with guess number of citation 
//typical mistake i was doing for this problem 
//1. i tried to take low and high array index 
//but low should be the lowest citation and high should be highest citation 
//and we need to guess between this range if we found book equal to guess number 
//then that can be answer and we will try to maxmimize this value 
//if we found citations > books , means books are less then we try to lower our guess 
//if we found citations < books means we need to raise our guess
//one more mistake take lowest citation as 0 , if there is only one number in array and we have to guess then we need range we cant take lowest and highest by one number so use 0 to highest as range
    int guessCount(vector<int>& citations , int guess){
        int count = 0 ; 
        for(auto citation : citations){
            if(citation >= guess) count++ ; 
        }
        return count ;
    }
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0 , high = citations[n-1]; 
        int ans = 0;
        while(low <= high){
            int guess = (low + high)/2 ;

            int hCount = guessCount(citations , guess);
            if(hCount >= guess){
                ans = guess ;
                low = guess + 1 ;
            }
            else 
                high = guess-1 ;
        }
        return ans ;
    }
};