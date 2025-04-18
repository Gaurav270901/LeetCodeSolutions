class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positiveArray ;
        vector<int> negativeArray ; 
        vector<int> ans ; 

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] > 0){
                positiveArray.push_back(nums[i]);
            }
            else{
                negativeArray.push_back(nums[i]);
            }
        }
        int j = 0 , k = 0 ; 
         for(int i = 0 ; i < nums.size() ; i++){
            if( i % 2 == 0){
                 ans.push_back(positiveArray[j]);
                 j++;
            }
            else{
                 ans.push_back(negativeArray[k]);
                 k++;
            }
        }
        return ans ; 
    }
};