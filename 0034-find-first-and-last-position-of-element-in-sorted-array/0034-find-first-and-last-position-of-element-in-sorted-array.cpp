class Solution {
public:

    int firstOccurance(vector<int>& nums , int target){
        int size = nums.size();
        int low = 0 , high = size -1 , ans = -1 ;
        while(low <= high){
            int mid = (low+high)/2;
            int value = nums[mid];

            if(value == target){
                high = mid -1 ;
                ans = mid;
            }
            else if(value > target)
                high = mid-1 ;
            else 
                low = mid + 1;
        }
        return ans ;
    }

     int lastOccurance(vector<int>& nums , int target){
        int size = nums.size();
        int low = 0 , high = size -1 , ans = -1 ;
        while(low <= high){
            int mid = (low+high)/2;
            int value = nums[mid];

            if(value == target){
                low = mid +1 ;
                ans = mid;
            }
            else if(value > target)
                high = mid-1 ;
            else 
                low = mid + 1;
        }
        return ans ;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans ; 
        ans.push_back(firstOccurance(nums , target));
        ans.push_back(lastOccurance(nums , target));

        return ans;

    }
};