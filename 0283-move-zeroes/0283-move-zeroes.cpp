class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0 , size = nums.size();
        for(int j = 0 ; j < size ; j++){
            if(nums[j] != 0){
                nums[i]= nums[j];
                i++;
            }

        }
        for(;i < size ; i++){
            nums[i] = 0 ;
        }
        
    }
};