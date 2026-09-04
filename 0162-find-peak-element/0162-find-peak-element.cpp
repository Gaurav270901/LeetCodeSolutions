class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high){
            int mid = (low + high)/2 ;
            int value = nums[mid];
            if (nums[mid] > nums[mid + 1])
                high = mid;      // descending slope, peak lies at mid or on the left
            else
                low = mid + 1;   // ascending slope, peak lies on the right
        }
        return low ;
    }
};