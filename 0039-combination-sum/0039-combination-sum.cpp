class Solution {
public: 

    void backtrack(vector<int>& candidates , vector<int> &current , int currentSum , vector<vector<int>>& ans , int target , int index ){
       //
            if(currentSum == target){
                ans.push_back(current);
                return ;
            }
            
        if(currentSum > target || index == candidates.size()) return ;
//first we will include current element in our addition and then take that element again in repeat call as seen in backtrack we are sentting the same index
        current.push_back(candidates[index]);
        backtrack(candidates,current,currentSum + candidates[index],ans , target,index );

//now we will exclude that element from combination and take next index
        current.pop_back();
        backtrack(candidates , current , currentSum , ans , target , index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int> current ;

        backtrack(candidates , current , 0 , ans , target ,0 );
        return ans ;
    }
};