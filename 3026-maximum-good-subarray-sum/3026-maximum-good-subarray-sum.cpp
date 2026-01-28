class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long prefixSum = 0  , ans = LLONG_MIN ;
        unordered_map<int , long long> map;
        for(int i = 0 ; i < nums.size();i++){
            if(map.count(nums[i] - k)){
                ans = max(ans , prefixSum+nums[i]-map[nums[i]-k]);
            }
            if(map.count(nums[i] + k)){
                ans = max(ans , prefixSum+nums[i]-map[nums[i]+k]);
            }

            if(!map.count(nums[i])){
                map[nums[i]] = prefixSum;
            }
            else {
                map[nums[i]] = min(map[nums[i]], prefixSum);
            }

            prefixSum += nums[i];
        }
        return (ans!= LLONG_MIN) ? ans : 0;
    }
};