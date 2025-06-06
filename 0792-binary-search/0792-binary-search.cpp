class Solution {
public:
    int search(vector<int>& nums, int target) {
        //binary search
        int n = nums.size()-1 ; 
        int low = 0 ; 
        int high = n ; 
        while(low <= high){
            int mid = (low+high)/2 ; 
            if(nums[mid] == target) return (mid);
            if( nums[mid] < target){
                low = mid +1 ;
            }
            else{
                high = mid -1; 
            }
        }

        return -1 ; 
    }
};