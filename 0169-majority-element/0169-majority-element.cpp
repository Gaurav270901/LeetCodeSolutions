class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxCount = 0 , majorElement , n = nums.size() ;

        for(int i = 0 ; i < n ; i++ )
        {
            if(maxCount == 0 ) majorElement = nums[i];

            if(nums[i] == majorElement){
                maxCount++;
            }
            else{
                maxCount--;
            }
        }

        return majorElement ;
    }
};