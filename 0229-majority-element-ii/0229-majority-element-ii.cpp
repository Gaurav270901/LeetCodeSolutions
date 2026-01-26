class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int cdOneCount = 0 , cdTwoCount = 0 , cdOne = INT_MIN , cdTwo = INT_MIN ;
      vector<int> ans ; 
      for(int i = 0 ; i < nums.size();i++){
        if(nums[i]==cdOne) cdOneCount++;
        else if (nums[i]==cdTwo) cdTwoCount++;
        else if (cdOneCount == 0){
            cdOne = nums[i];
            cdOneCount = 1 ;
        }
        else if(cdTwoCount == 0){
            cdTwo = nums[i];
            cdTwoCount = 1;
        }
        else{
            cdOneCount--;
            cdTwoCount--;
        }
      }
    
        cdOneCount = cdTwoCount = 0 ;
      for(int i = 0 ; i < nums.size();i++){
        if(nums[i]==cdOne) cdOneCount++;
        if(nums[i]==cdTwo) cdTwoCount++;
      }

        if ((cdOneCount ) > nums.size()/3 ) ans.push_back(cdOne);
        if ((cdTwoCount ) > nums.size()/3 ) ans.push_back(cdTwo);
        return ans;
    }

};