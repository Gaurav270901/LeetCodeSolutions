class Solution {
    //maxEnd : max product finising at index i 
    //mindEnd : min product finishing at index i

    //at each index we will find this two pointer and then we will which one to pic , if minEnd is negative and i is also negative at that time there is possibilty at it can create max positive product ,
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() < 2) return nums[0];
        int n = nums.size() , maxEnd = nums[0] , minEnd = nums[0] , ans = nums[0] ; 

        for(int i = 1 ; i < n ; i++){
            int currentMin = minEnd * nums[i];
            int currentMax = maxEnd * nums[i];
            maxEnd = max(nums[i] , max(currentMin , currentMax));
            minEnd = min(nums[i] , min(currentMin , currentMax));

            ans = max(ans , max(maxEnd , minEnd));
        }
        return ans;
    }
};