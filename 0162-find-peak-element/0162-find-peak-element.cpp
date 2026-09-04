class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high){
            int mid = (low + high)/2 ;
            int value = nums[mid];

            if(value > nums[mid+1])
                high = mid ;
            else
                low = mid+1 ;
        }
        return low ;
    }
};