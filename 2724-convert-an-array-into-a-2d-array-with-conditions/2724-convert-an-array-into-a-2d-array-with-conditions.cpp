class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
          map<int, vector<int>> mp; // Use map to directly store vectors of integers
        int maxCount = 0;

        for (int num : nums) {
            mp[num].push_back(num);
            maxCount = max(maxCount, (int)mp[num].size());
        }

        vector<vector<int>> ans(maxCount);

        for (auto& pair : mp) {
            int freq = pair.second.size();
            for (int i = 0; i < freq; ++i) {
                ans[i].push_back(pair.first);
            }
        }

        return ans;
    }
};