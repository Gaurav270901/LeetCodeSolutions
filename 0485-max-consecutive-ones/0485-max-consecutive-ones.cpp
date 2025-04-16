class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0 ;
        int consOnes = 0 ; 
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]==1){
                consOnes++;
                if(consOnes > maxOnes ) {
                    maxOnes = consOnes ; 
                }
            }
            else {
                consOnes = 0 ; 
            }
        
        }
        return maxOnes ; 
    }
};