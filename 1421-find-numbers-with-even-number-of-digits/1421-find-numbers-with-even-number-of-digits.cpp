class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenCount = 0 ; 
        for(int num : nums){
            int count = 0 ;
            for( ; num!=0 ; num = num/10 , count++);
            if(count%2== 0) evenCount++ ; 
        }
        return evenCount;
    }
};