class Solution {
public:
//for this problem we will guess one number which will act as a minimum sum then we try to add elements from array within that guess 
//and keep count of subarray if we can fit it in guess then we will minimize the guess ,otherwise increase the guess
//as its need to be subarray we need to take low as first element because if we take low = 2 and first element is 7 it cant fit in subarray where guess is 2 
//max should be sum of all elements from the array

    int isGuessValid(vector<int>& nums, int guess){
        int subArrayCount = 1 ; 
        int sum = 0 ; 
        for(auto num : nums){
            if(sum + num > guess){
                subArrayCount++ ; 
                sum = num ;
            }
            else 
                sum += num ;
        }
        return subArrayCount;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = 0 ; 
        int ans = -1;
        for(auto num : nums) high += num ; 
        while(low <= high){
            int guess = (low+high)/2 ;
            int countSubArray = isGuessValid(nums, guess) ;
            if(countSubArray <= k){
                ans = guess ; 
                high = guess-1 ;
            }
            else
                low = guess + 1 ;
        }
        return ans ;

    }
};