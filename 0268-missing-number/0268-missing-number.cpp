class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int actualSum = 0 ; 
        int size = nums.size();
        int expectedSum = size*(size+1)/2;

        for(int num : nums){
            actualSum+= num ; 
        }

        return expectedSum-actualSum ; 
    }
};