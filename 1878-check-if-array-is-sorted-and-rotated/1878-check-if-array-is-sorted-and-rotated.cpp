class Solution {
public:
    bool check(vector<int>& nums) {
      //here we have to check how many times did array changes its inversion , if its sorted only then it will  change inversion zero times if its sorted and rotated then one time and more than that is not sorted and rotated 
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