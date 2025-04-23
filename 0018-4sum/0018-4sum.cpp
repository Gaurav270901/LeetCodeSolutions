class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //do the same as two sum and three sum after finding the first and second element set left and right
       vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; ++j) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        // Skip duplicates for the third number
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        // Skip duplicates for the fourth number
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                    else if (sum < target) left++;
                    else right--;
                }
            }
        }

        return result;
    }
};