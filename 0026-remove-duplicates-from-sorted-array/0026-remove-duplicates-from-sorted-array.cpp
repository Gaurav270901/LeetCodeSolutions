class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1 ; 
        int ans = 1 , low = 0 , high = 1;
        while(high < nums.size()){
            if(nums[low]==nums[high]){
                high++;
                continue ;
            }
            nums[++low] = nums[high];
            high++;
            ans++;
        }
        return ans;
    }
};