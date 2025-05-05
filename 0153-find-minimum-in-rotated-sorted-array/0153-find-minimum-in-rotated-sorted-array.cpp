class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 ; 
        int high = nums.size()-1 ; 
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            //check if first half is sorted 
            if(nums[low]<=nums[mid]){
                //sorted - so leftmost element is minimum
                ans = min(ans , nums[low]);
                //eliminate left part
                low = mid+1 ;
            }
            else{
                //check minimum from mid and ans
                ans = min(ans , nums[mid]);
                //eliminate right part
                high = mid-1;
            }
        }
        return ans ; 
    }
};