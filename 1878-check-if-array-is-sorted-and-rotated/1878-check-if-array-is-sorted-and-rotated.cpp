class Solution {
public:
    bool check(vector<int>& nums) {
      
       int countInversion = 0 ;
       int length = nums.size(); 
       for(int i = 0 ; i < length;i++) 
       {
         if (nums[i%length] > nums[(i+1)%length]) 
         {
           countInversion++;
         }
       }

        if(countInversion >= 2) return false ; 

       return true ; 

    }
};