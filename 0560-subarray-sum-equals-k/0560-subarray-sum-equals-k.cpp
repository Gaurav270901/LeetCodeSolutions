class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixMap;
    prefixMap[0] = 1;  // Base case: to handle subarrays that start at index 0

    int count = 0;
    int prefixSum = 0;

    for (int num : nums) {
        prefixSum += num;

        // Check if there's a prefixSum that we can subtract to get k
        if (prefixMap.find(prefixSum - k) != prefixMap.end()) {
            count += prefixMap[prefixSum - k];
        }

        // Store/update current prefixSum count
        prefixMap[prefixSum]++;
    }

    return count;
    }
};