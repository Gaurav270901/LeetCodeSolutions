class Solution {
public: 

    void backtrack(vector<int>& candidates , vector<int> &current , int currentSum , vector<vector<int>>& ans , int target , int index , int size){
       
            if(currentSum == target){
                ans.push_back(current);
                return ;
            }
            
        if(currentSum > target || index == size) return ;

        current.push_back(candidates[index]);
        backtrack(candidates,current,currentSum + candidates[index],ans , target,index , size);

        current.pop_back();
        backtrack(candidates , current , currentSum , ans , target , index+1 , size);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int> current ;

        backtrack(candidates , current , 0 , ans , target ,0 ,candidates.size() );
        return ans ;
    }
};