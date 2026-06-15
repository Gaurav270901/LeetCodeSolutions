class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0 , prefixSum = 0 ; 
        for(int i = 0 ; i < nums.size() ; i++){
            totalSum+= nums[i];
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(i != 0)
                prefixSum += nums[i-1];
            int suffixSum = totalSum - nums[i] - prefixSum ;
            if(prefixSum == suffixSum) return i ;
        }
        return - 1;
    }
};