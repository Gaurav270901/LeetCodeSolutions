class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0 , candidate = 0 , n = nums.size()  ;

       for (int i = 0 ; i < n ;i++) {
            if (count == 0) candidate = nums[i];
            count += (nums[i] == candidate) ? 1 : -1;
        }

        return candidate ;
    }
};