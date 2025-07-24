class Solution {
public:
//as there are duplicates element in this array we will sort this array so it will be effiecient to skip the pair forming duplicate pair
    void backtrack(vector<int> &candidates , vector<vector<int>>& ans , vector<int>& current , int currentSum , int index , int target){
        if(currentSum == target){
            ans.push_back(current);
            return ;
        }
        for(int i = index ; i < candidates.size() ; i++){   
            //if duplicate element skip it 
            if(i > index && candidates[i]==candidates[i-1]) continue ;
            
            if(currentSum+candidates[i] > target) break;

            current.push_back(candidates[i]);
            backtrack(candidates , ans , current , currentSum+candidates[i], i+1 , target);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int> current ;
        sort(candidates.begin() , candidates.end());
        backtrack(candidates , ans , current , 0 , 0 , target);
        return ans ;
    }
};