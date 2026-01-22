class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int > map ; 
        vector<int> ans ; 

        for(int i = 0 ; i < nums.size() ; i++){
            int value = target - nums[i];
            if(map.find(value) != map.end()){
                ans.push_back(map.find(value)->second );
                ans.push_back(i);
                return ans ; 
            }

            map.insert(pair<int , int > (nums[i],i));
        }
        return ans ; 
    }
};